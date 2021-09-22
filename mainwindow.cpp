#include "mainwindow.h"

#include <QTextEdit>
#include <QDebug>
#include <QString>
#include <QTextCodec>
//#include <string.h>
#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    flag_line=0;
    flag_text=0;

    m_arrey.clear();

    threadForServer = new QThread;
    Serv = new LocalServer;
    Serv->moveToThread(threadForServer);
    threadForServer->start();

    connect(Serv, &LocalServer::signalLog, this, &MainWindow::addLog);
    connect(Serv, &LocalServer::signalData, this, &MainWindow::slotNewData);

    connect(tabWidget, &QTabWidget::currentChanged, this, &MainWindow::slotChangeType);

    tabWidget->setCurrentIndex(0);
    td_display=TWO_LINE_ADM;

    Serv->init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::addLog(QString str)
{

    if(str.contains("##!!", Qt::CaseInsensitive))
    {
        str.replace("##!!", "Port: ");
        l_port->setText(str);
    }

    if(cb_log->checkState()==Qt::Checked)
    {
        te_log->append(str);
    }

}

void MainWindow::slotChangeType(int t)
{
    if(tabWidget->tabText(t)==QString("2 string"))
    {
        td_display=TWO_LINE_ADM;
        l_protokol->setText("Protocol: adm");
        addLog("TWO_LINE_ADM");
    }
    else if(tabWidget->tabText(t)==QString("Basket View"))
    {
        td_display=BASKET_VIEW;
        l_protokol->setText("Protocol: basket view (CRM Sensor)");
        addLog("BASKET_VIEW");
    }
    else
    {
        addLog("Unnow type");
    }
}

void MainWindow::slotNewData(QByteArray arr)
{
    QString log;
    log.clear();
    // for test
    arr = arr.simplified();
    //arr = arr.trimmed();
    //arr.clear();
    //arr.append("{\"promo\":{\"text\": \"Test promo text\"}}");
    // ***
    if(cb_hex->checkState()==Qt::Checked)
    {
        char *buf=arr.data();
        size_t len = strlen(buf);
        for(unsigned long i=0; i<len; i++)
        {
            log.append(QByteArray(1,buf[i]).toHex()+" ");
        }
    }
    else
    {
        log.append(arr);
    }
    addLog(log);

    if(td_display==TWO_LINE_ADM)
    {
        slotNewDataTwoString(arr);
    }
    else if(td_display==BASKET_VIEW)
    {
        slotNewDataBasketView(arr);
    }

}

void MainWindow::slotNewDataBasketView(QByteArray arr)
{
    //m_arrey.append(arr);
    m_arrey=arr;
    //addLog(m_arrey+QString(" %1").arg(m_arrey.length()));
    QJsonParseError *error = new QJsonParseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(m_arrey, error);
    if(jsonResponse.isEmpty())
    {
        addLog("Error parse: "+error->errorString());
        delete error;
        return;
    }
    delete error;

    //addLog(QString(jsonResponse.toJson(QJsonDocument::Compact)));
    QJsonObject jsonObject = jsonResponse.object(); // все один большой объект



    for(auto i=jsonObject.begin(); i!=jsonObject.end(); ++i)
    {
        if(i.key()=="receipt")  // текущий чек
        {
                te_basket->clear();
                QJsonObject joo = i.value().toObject();
                QJsonArray arr = joo.value("positions").toArray();
                for(auto j=arr.begin(); j!=arr.end(); ++j)
                {
                    if(j->isObject())
                    {
                        QJsonObject jo = j->toObject();
                        QString ss;
                        ss.append(QString("[%1] ").arg(jo.value("number").toInt(-1))+jo.value("name").toString()+"\n");
                        ss.append(QString("        %1 * %2 = %3").arg(jo.value("price").toDouble()).arg(jo.value("quantity").toDouble()).arg(jo.value("amount").toDouble()));
                        te_basket->append(ss);
                    }
                }

                te_basket->append("ИТОГО: "+QString("%1").arg(joo.value("amount").toDouble()));

        }
        else if(i.key()=="total")
        {
            te_total->clear();
            QJsonObject jot = i.value().toObject();
            te_total->append("\nИтоговая стоимость по всем позициям: "+QString("%1").arg(jot.value("positionsAmount").toDouble())
                              +"\nСумма скидки: "+QString("%1").arg(jot.value("bonusAmount").toDouble())
                              +"\nСумма к оплате: "+QString("%1").arg(jot.value("totalAmount").toDouble())
                              +"\nТекст для генерации QR-кода для оплаты через СБП: "+jot.value("totalAmountSbpText").toString()+"\n");
        }
        else if(i.key()=="purchase")
        {
            te_pur_ref->clear();
            QJsonObject jop = i.value().toObject();

            te_pur_ref->append("Сумма к оплате: "+QString("%1").arg(jop.value("totalAmount").toDouble()));
            te_pur_ref->append("Способ оплаты: "+jop.value("type").toString());
            te_pur_ref->append("Сумма полученных от клиента денег: "+QString("%1").arg(jop.value("receivedAmount").toDouble())
                              +"\nСумма сдачи: "+QString("%1").arg(jop.value("changeAmount").toDouble()));
        }
        else if(i.key()=="cancel")
        {
            te_promotions->clear();
            te_basket->clear();
            te_total->clear();
            te_bonusCard->clear();
            te_pur_ref->clear();
        }
        else if(i.key()=="refund")
        {
            te_pur_ref->clear();
            QJsonObject jor = i.value().toObject();
            te_pur_ref->append(QString("Сумма к возврату: %1").arg(jor.value("amount").toDouble()));
        }
        else if(i.key()=="bonusCard")
        {
            te_bonusCard->clear();
            QJsonObject jobc = i.value().toObject();
            te_bonusCard->append("\nНомер бонусной карты: "+jobc.value("cardNumber").toString()
                              +"\nФИО владельца карты: "+jobc.value("cardHolder").toString()
                              +"\nКол-во бонусных баллов: "+QString("%1").arg(jobc.value("points").toDouble())+"\n");
        }
        else if(i.key()=="promo")
        {
            te_promotions->clear();
            //QJsonObject jop = i.value().toObject();
            //te_promotions->append(jop.value("text").toString());
            QJsonArray arr = i.value().toArray();
            for(auto j=arr.begin(); j!=arr.end(); ++j)
            {
                if(j->isObject())
                {
                    QJsonObject jo = j->toObject();
                    QString ss;
                    te_promotions->append("Название картинки: "+jo.value("picture_fname").toString());
                    te_promotions->append("Текст: "+jo.value("text").toString());
                }
            }



        }
        else
        {
            addLog("Unnow type in json");
        }
    }


    m_arrey.clear();


}



void MainWindow::slotNewDataTwoString(QByteArray arr)
{
    QTextCodec *codec = QTextCodec::codecForName("CP866");

    char *buf=arr.data();
    size_t len = strlen(buf);

    for(unsigned long i=0; i<len; i++)
    {
        switch(buf[i])
        {
            case '\x0E': // line 1
            {
                flag_line=1;
                break;
            }
            case '\x0F': // line 2
            {
                flag_line=2;
                break;
            }
            case '\x0C': //cls
            {
                flag_text=1;
                le_line1->clear();
                le_line2->clear();
                break;
            }
            default:
            {
                if(flag_line==1)
                {
                    le_line1->setText(le_line1->text()+codec->toUnicode(buf+i, 1));
                }
                else
                {
                    le_line2->setText(le_line2->text()+codec->toUnicode(buf+i, 1));
                }
            }
        }
    }
}

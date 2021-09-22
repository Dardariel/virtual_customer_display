/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *two_string;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *le_line1;
    QLineEdit *le_line2;
    QSpacerItem *verticalSpacer;
    QWidget *basket_view;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *te_promotions;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *te_total;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *te_bonusCard;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *te_pur_ref;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *te_basket;
    QHBoxLayout *horizontalLayout;
    QLabel *l_protokol;
    QSpacerItem *horizontalSpacer;
    QLabel *l_port;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cb_log;
    QCheckBox *cb_hex;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *te_log;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(727, 874);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        two_string = new QWidget();
        two_string->setObjectName(QString::fromUtf8("two_string"));
        verticalLayout_3 = new QVBoxLayout(two_string);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        le_line1 = new QLineEdit(two_string);
        le_line1->setObjectName(QString::fromUtf8("le_line1"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        le_line1->setFont(font);
        le_line1->setReadOnly(true);

        verticalLayout_3->addWidget(le_line1);

        le_line2 = new QLineEdit(two_string);
        le_line2->setObjectName(QString::fromUtf8("le_line2"));
        le_line2->setFont(font);
        le_line2->setReadOnly(true);

        verticalLayout_3->addWidget(le_line2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(two_string, QString());
        basket_view = new QWidget();
        basket_view->setObjectName(QString::fromUtf8("basket_view"));
        horizontalLayout_8 = new QHBoxLayout(basket_view);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(basket_view);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        te_promotions = new QTextEdit(groupBox);
        te_promotions->setObjectName(QString::fromUtf8("te_promotions"));

        horizontalLayout_2->addWidget(te_promotions);


        verticalLayout_5->addWidget(groupBox);

        groupBox_4 = new QGroupBox(basket_view);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        te_total = new QTextEdit(groupBox_4);
        te_total->setObjectName(QString::fromUtf8("te_total"));

        horizontalLayout_6->addWidget(te_total);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(basket_view);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_5);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        te_bonusCard = new QTextEdit(groupBox_5);
        te_bonusCard->setObjectName(QString::fromUtf8("te_bonusCard"));

        horizontalLayout_7->addWidget(te_bonusCard);


        verticalLayout_5->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(basket_view);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        te_pur_ref = new QTextEdit(groupBox_2);
        te_pur_ref->setObjectName(QString::fromUtf8("te_pur_ref"));

        horizontalLayout_4->addWidget(te_pur_ref);


        verticalLayout_5->addWidget(groupBox_2);


        horizontalLayout_8->addLayout(verticalLayout_5);

        groupBox_3 = new QGroupBox(basket_view);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        te_basket = new QTextEdit(groupBox_3);
        te_basket->setObjectName(QString::fromUtf8("te_basket"));

        horizontalLayout_5->addWidget(te_basket);


        horizontalLayout_8->addWidget(groupBox_3);

        tabWidget->addTab(basket_view, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        l_protokol = new QLabel(layoutWidget);
        l_protokol->setObjectName(QString::fromUtf8("l_protokol"));

        horizontalLayout->addWidget(l_protokol);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        l_port = new QLabel(layoutWidget);
        l_port->setObjectName(QString::fromUtf8("l_port"));

        horizontalLayout->addWidget(l_port);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cb_log = new QCheckBox(layoutWidget1);
        cb_log->setObjectName(QString::fromUtf8("cb_log"));

        horizontalLayout_3->addWidget(cb_log);

        cb_hex = new QCheckBox(layoutWidget1);
        cb_hex->setObjectName(QString::fromUtf8("cb_hex"));

        horizontalLayout_3->addWidget(cb_hex);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        te_log = new QTextEdit(layoutWidget1);
        te_log->setObjectName(QString::fromUtf8("te_log"));

        verticalLayout_2->addWidget(te_log);

        splitter->addWidget(layoutWidget1);

        verticalLayout_4->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Custommer display", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(two_string), QApplication::translate("MainWindow", "2 string", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Promo", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Total", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Bonus card", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "purchase/refund", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Receipt", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(basket_view), QApplication::translate("MainWindow", "Basket View", nullptr));
        l_protokol->setText(QApplication::translate("MainWindow", "Protocol: adm", nullptr));
        l_port->setText(QApplication::translate("MainWindow", "Port: ", nullptr));
        cb_log->setText(QApplication::translate("MainWindow", "Log", nullptr));
        cb_hex->setText(QApplication::translate("MainWindow", "Hex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

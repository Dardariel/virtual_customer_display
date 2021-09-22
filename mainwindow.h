#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "ui_mainwindow.h"

#include "localserver.h"

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addLog(QString str);

    LocalServer *Serv;
    QThread *threadForServer;

    int flag_line;
    int flag_text;


    enum TYPE_DISPLAY
    {
        TWO_LINE_ADM,
        BASKET_VIEW
    };

    TYPE_DISPLAY td_display;

    QByteArray m_arrey;

public slots:
    void slotNewData(QByteArray arr);
    void slotNewDataBasketView(QByteArray arr);
    void slotNewDataTwoString(QByteArray arr);
    void slotChangeType(int t);
};

#endif // MAINWINDOW_H

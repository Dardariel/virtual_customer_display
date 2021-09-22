#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>
#include <QTimer>

#define SIZE_OF_DATA 2048

class LocalServer : public QObject
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = nullptr);
    ~LocalServer();
    bool init();


signals:
    void signalLog(QString);
    void signalData(QByteArray);

public slots:
    //void slotData(QByteArray);

private slots:

    void slotReadTimeout();


private:
    QTimer *ReadData;
    int FD;

};

#endif // LOCALSERVER_H

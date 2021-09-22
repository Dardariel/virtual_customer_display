#include "localserver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>
#include <termio.h>

LocalServer::LocalServer(QObject *parent) : QObject(parent)
{
    FD=0;
    ReadData = new QTimer;
    connect(ReadData, &QTimer::timeout, this, &LocalServer::slotReadTimeout);
}
LocalServer::~LocalServer()
{
    if(FD>0)
    {
        close(FD);
    }
    delete ReadData;
}

bool LocalServer::init()
{
// init
    char *ptr;
    FD = posix_openpt(O_RDWR | O_NONBLOCK);
    if (FD < 0)
    {
        emit signalLog("ERROR opening file");
        return false;
    }

    if (grantpt(FD) < 0)
    {
        close(FD);
        emit signalLog("ERROR grantpt file");
        return false;
    }

    if (unlockpt(FD) < 0)
    {
        close(FD);
        emit signalLog("ERROR unlockpt file");
        return false;
    }

    if ((ptr = ptsname(FD)) == NULL)
    {
        close(FD);
        emit signalLog("ERROR ptsname file");
        return false;
    }

// conf

    int rc;
    struct termios params;

    // Get terminal atributes
    rc = tcgetattr(FD, &params);

    // Modify terminal attributes
    cfmakeraw(&params);

    rc = cfsetispeed(&params, B9600);

    rc = cfsetospeed(&params, B9600);

    // CREAD - Enable port to read data
    // CLOCAL - Ignore modem control lines
    params.c_cflag |= (B9600 |CS8 | CLOCAL | CREAD);

    // Make Read Blocking
    //fcntl(serialDev, F_SETFL, 0);

    // Set serial attributes
    rc = tcsetattr(FD, TCSANOW, &params);

    // Flush serial device of both non-transmitted
    // output data and non-read input data....
    tcflush(FD, TCIOFLUSH);

    emit signalLog("##!!"+QString(ptr));

    ReadData->start(100);

    return true;

}
void LocalServer::slotReadTimeout()
{
    fd_set rfds;
    int retval;
    FD_ZERO(&rfds);
    FD_SET(FD, &rfds);
    retval = select(FD + 1, &rfds, NULL, NULL, NULL);
    if (retval == -1)
    {
        emit signalLog("ERROR select file");
        return;
    }
    if (FD_ISSET(FD, &rfds))
    {
        ssize_t br, bw;
        char pbuf[SIZE_OF_DATA]={0};
        br = read(FD, pbuf, SIZE_OF_DATA);
        if (br < 0)
        {
            if (errno == EAGAIN || errno == EIO)
            {
                br = 0;
            }
            else
            {
                emit signalLog("ERROR read file");
                return;
            }
        }
        if(br > 0)
        {
            QByteArray arr;
            for(int i=0; i<SIZE_OF_DATA; i++)
            {
                if(pbuf[i]=='\0')
                {
                    break;
                }
                arr.append(pbuf[i]);
            }
            emit signalData(arr);
        }
    }
}



#include "qt_server.h"

#include <QtGui>
#include <QApplication>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <QMessageBox>
#include <QMutex>
#include <sys/ioctl.h>
#include <net/if.h>
#include<unistd.h>
#include<QTextCodec>
#include<QByteArray>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qt_server w;
    w.show();
    return a.exec();
}

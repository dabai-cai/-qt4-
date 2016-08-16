#include "qt_client.h"
#include "conn.cpp"
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <QMutex>
#include <QMessageBox>
#include<unistd.h>
#include<QDebug>
#include<QDateTime>
int sock;
qt_client::qt_client(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
    connect(&thd, SIGNAL( recv_msg_signal(QString) ), this, SLOT( update_msg(QString) ),Qt::QueuedConnection);
    connect(&thd, SIGNAL( err_msg_signal(QString) ), this, SLOT( err_msg_update(QString) ),Qt::QueuedConnection);
    connect(ui.pushButton, SIGNAL( clicked() ), this, SLOT( send_msg() ),Qt::QueuedConnection);
    connect(ui.pushButton_2, SIGNAL( clicked() ), this, SLOT( conn() ),Qt::QueuedConnection);
}

qt_client::~qt_client()
{
	
}

void qt_client::err_msg_update(QString s)
{
	ui.textEdit->append(s);
}
void recv_thd::run()
{
    int res;
    char msg[1024];
    while(1)
        {
            if( (res = recv(sock, msg,1024, 0)) <= 0)
            {
                close(sock);
                emit err_msg_signal("<font color=red>lost connection</font>");
                break;
            }
            else
            {
                msg[res] = '\0';
                emit recv_msg_signal("<font color=green>" + QString::fromUtf8(msg) + "</font>");
            }
        }
}

void qt_client::send_msg()
{
     QString name=ui.lineEdit_4->text();
	if(sock == -1 || sock == 0)
		{
			QMessageBox::about(this, "", "please connect first or reconnect");
		}
		else
		{
			QString s;
			s = ui.lineEdit->text();
            QString message=name+" : "+s;
			if(s == "")
			{
				QMessageBox::about(this, "", "empty");
			}
            else
			{
                QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
                QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
                QString t=" ( "+str+" )";
                  ui.textEdit->append("<font color=blue>"+message+"</font>"+t);
          send(sock, message.toUtf8().data(), strlen(message.toUtf8().data()), 0);
				ui.lineEdit->setText("");
				ui.lineEdit->setFocus();
			}
		}
}

void qt_client::conn()
{
	int re;
	QString ip = ui.lineEdit_2->text();
    QString name=ui.lineEdit_4->text();
    re = conn_server(ip, "8088",name);
    switch(re)
	{
	case 0:
		QMessageBox::about(this, "", "create socket error");
		break;
	case 1:
		QMessageBox::about(this, "", "connect error");
		break;
	default:
		ui.textEdit->append("<font color=red>connect successed</font>");
		thd.start();
		break;
	}
}

void qt_client:: update_msg(QString s)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    QString t=" ( "+str+" )";
    ui.textEdit->append("<font color=green></font>" + s+"   "+t);
}

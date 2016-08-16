#include "qt_server.h"
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <QMessageBox>
#include <sys/ioctl.h>
#include <net/if.h>
#include<unistd.h>
#include<QMutex>
#include<QDebug>
int sock;int sum=0;
QString client_info;
QMutex mutex;
int SOCK[1024];
char msg[1024];
qt_server::qt_server(QWidget *parent)
    : QWidget(parent)
{qDebug
	ui.setupUi(this);
    connect(&thd, SIGNAL( recv_msg_signal(QString) ), this, SLOT( update_msg(QString) ));
    connect(&thd, SIGNAL( err_msg_signal(QString) ), this, SLOT( err_msg_update(QString) ));
    thd.start(QThread::HighestPriority);
    connect(ui.pushButton, SIGNAL( clicked() ), this, SLOT( send_msg() ));

	int inet_sock;
	struct ifreq ifr;

	inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
	strcpy(ifr.ifr_name, "eth0");
    ioctl(inet_sock, SIOCGIFADDR, &ifr);
	ui.textEdit->append("local ip address is : "
			+ QString::fromLatin1(inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr)) );

}

qt_server::~qt_server()
{

}

void qt_server::send_msg()
{
	if(sock == -1 || sock == 0)
			{
				QMessageBox::about(this, "", "client have not connected yet");
			}
			else
			{
				QString s;
				s = ui.lineEdit->text();
                QString ser="server :"+s;
				if(s == "")
				{
					QMessageBox::about(this, "", "empty");
				}
				else
				{
					ui.textEdit->append("<font color=green>server : " + s + "</font>");
                    for(int i=0;i<sum;i++)
                    send(SOCK[i], ser.toUtf8().data(), strlen(ser.toUtf8().data()), 0);
					ui.lineEdit->setText("");
					ui.lineEdit->setFocus();
				}
			}
}

void qt_server::err_msg_update(QString s)
{
	ui.textEdit->append("<font color=red>" + s + "</font>");
}
void qt_server::update_msg(QString s)
{
	ui.textEdit->append("<font color=blue>client  : " + s + "</font>");
    for(int i=0;i<sum;i++)
        if(sock!=SOCK[i])
            send(SOCK[i],msg,strlen(msg),0);
}

void recv_thd::run()
{

		int Listen_socket;
		struct sockaddr_in local_addr;
		struct sockaddr_in client_addr;
		if( (Listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		{
			emit err_msg_signal("failed create socket");
		}
		local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(8088);
		local_addr.sin_addr.s_addr = INADDR_ANY;
		
		if(bind(Listen_socket, (struct sockaddr*)&local_addr, sizeof(struct sockaddr)) == -1)
		{
			emit err_msg_signal("failed bind");
		}
		
		if(listen(Listen_socket, 5) == -1)
		{
			emit err_msg_signal("failed listen");
		}
		socklen_t addr_size;
		addr_size = sizeof(struct sockaddr_in);

        while(true){
        mutex.lock();
        sock = accept(Listen_socket, (struct sockaddr *)&client_addr, &addr_size);
        mutex.unlock();
        if(sock==-1)
		{
				emit err_msg_signal("failed accept");
        }
		else
        {
            SOCK[sum++]=sock;
			emit err_msg_signal("client ip: " + QString::fromLatin1(inet_ntoa(client_addr.sin_addr)) + 
					" port: " + QString::number(ntohs(client_addr.sin_port)));
           rev=new qt_rec(sock);
           QThread *temp=new QThread();
           connect(temp, SIGNAL(started()), rev, SLOT(threadStarted()), Qt::QueuedConnection );
           rev->moveToThread(temp);
           temp->start();
		}

        }
}

qt_rec::qt_rec(int socket1)
{
   SOCK1=socket1;
}
qt_rec::~qt_rec()
{

}
void qt_rec::threadStarted(){
    while(true)
    {
       int res;char msgg[1024];
       res=recv(SOCK1,msgg,1024,0);
       msgg[res]='\0';
       if(res>=0)
           for(int i=0;i<sum;i++)
               if(SOCK1!=SOCK[i])
                   send(SOCK[i],msgg,strlen(msgg),0);
    }
}


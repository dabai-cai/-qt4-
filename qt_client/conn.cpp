#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int conn_server(QString ip, QString port,QString name)
{
	extern int sock;
	
	struct sockaddr_in server_addr;
	if( (sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
		return 0;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port.toInt());
	server_addr.sin_addr.s_addr = inet_addr(ip.toLatin1().data());
		
	if(connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
	{
		return 1;
	}
    else
    {
            return 2;
    }

}

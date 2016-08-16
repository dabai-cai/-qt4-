#ifndef REVC_THD_H_
#define REVC_THD_H_

#endif /*REVC_THD_H_*/
#include <QThread>

class recv_thd : public QThread
{
	Q_OBJECT
public:
	void run();
signals:
	void recv_msg_signal(QString);
	void err_msg_signal(QString);
};

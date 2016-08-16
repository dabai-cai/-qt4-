#ifndef RECV_THD_H_
#define RECV_THD_H_

#endif /*RECV_THD_H_*/
#include <QThread>
class qt_rec:public QObject
{
   Q_OBJECT
public:
    qt_rec(int s);
    ~qt_rec();
    int SOCK1;
public slots:
    void threadStarted();

};
class recv_thd: public QThread
{
	Q_OBJECT
public:
	void run();
     qt_rec *rev;
signals:
	void recv_msg_signal(QString);
	void err_msg_signal(QString);

};


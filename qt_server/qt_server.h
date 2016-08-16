

#ifndef QT_SERVER_H
#define QT_SERVER_H

#include <QtGui/QWidget>
#include "ui_qt_server.h"
#include<recv_thd.h>
class qt_server : public QWidget
{
    Q_OBJECT

public:
    qt_server(QWidget *parent = 0);
    ~qt_server();

private:
    Ui::qt_serverClass ui;
    recv_thd thd;

    QThread th;
private slots:
	void send_msg();
signals:
     void started();
public slots:
	void update_msg(QString);
	void err_msg_update(QString);

};

#endif // QT_SERVER_H

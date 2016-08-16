/********************************************************************************
** Form generated from reading UI file 'qt_client.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_CLIENT_H
#define UI_QT_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_clientClass
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QLabel *label_2;

    void setupUi(QWidget *qt_clientClass)
    {
        if (qt_clientClass->objectName().isEmpty())
            qt_clientClass->setObjectName(QString::fromUtf8("qt_clientClass"));
        qt_clientClass->resize(702, 504);
        textEdit = new QTextEdit(qt_clientClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(0, 0, 521, 291));
        textEdit->setReadOnly(true);
        lineEdit = new QLineEdit(qt_clientClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 300, 521, 161));
        pushButton = new QPushButton(qt_clientClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 480, 80, 27));
        pushButton_2 = new QPushButton(qt_clientClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 480, 80, 27));
        lineEdit_2 = new QLineEdit(qt_clientClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 470, 113, 27));
        label = new QLabel(qt_clientClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 470, 71, 20));
        lineEdit_4 = new QLineEdit(qt_clientClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 470, 111, 31));
        label_2 = new QLabel(qt_clientClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 480, 71, 17));

        retranslateUi(qt_clientClass);

        QMetaObject::connectSlotsByName(qt_clientClass);
    } // setupUi

    void retranslateUi(QWidget *qt_clientClass)
    {
        qt_clientClass->setWindowTitle(QApplication::translate("qt_clientClass", "qt_client", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("qt_clientClass", "send", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("qt_clientClass", "connect", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("qt_clientClass", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("qt_clientClass", "\346\234\215\345\212\241\345\231\250ip ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("qt_clientClass", "      \346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qt_clientClass: public Ui_qt_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_CLIENT_H

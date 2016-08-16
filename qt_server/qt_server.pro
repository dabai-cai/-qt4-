TEMPLATE = app
TARGET = qt_server
QT += core \
    gui
HEADERS += recv_thd.h \
    qt_server.h
SOURCES += main.cpp \
    qt_server.cpp
FORMS += qt_server.ui
RESOURCES += 

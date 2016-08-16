TEMPLATE = app
TARGET = qt_client
QT += core \
    gui
HEADERS += recv_thd.h \
    qt_client.h
SOURCES += conn.cpp \
    main.cpp \
    qt_client.cpp
FORMS += qt_client.ui
RESOURCES += 

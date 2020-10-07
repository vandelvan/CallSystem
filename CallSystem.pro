QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += Sources/main.cpp \
    Sources/agent.cpp \
    Sources/agentList.cpp \
    Sources/agentNode.cpp \
    Sources/callSystemMenu.cpp \
    Sources/customer.cpp \
    Sources/customerList.cpp \
    Sources/customerNode.cpp \
    Sources/date.cpp \
    Sources/duration.cpp \
    Sources/mainwindow.cpp

HEADERS += Headers/agent.h \
    Headers/agentList.h \
    Headers/agentNode.h \
    Headers/callSystemMenu.h \
    Headers/customer.h \
    Headers/customerList.h \
    Headers/customerNode.h \
    Headers/date.h \
    Headers/duration.h \
    Headers/mainwindow.h \

FORMS += Forms/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

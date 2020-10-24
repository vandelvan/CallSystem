QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += Sources/main.cpp \
    Sources/confirmDeleteAll.cpp \
    Sources/editDuration.cpp \
    Sources/start.cpp \
    Sources/agent.cpp \
    Sources/agentList.cpp \
    Sources/agentNode.cpp \
    Sources/callSystemMenu.cpp \
    Sources/customerUi.cpp \
    Sources/customer.cpp \
    Sources/customerList.cpp \
    Sources/customerNode.cpp \
    Sources/date.cpp \
    Sources/duration.cpp \
    Sources/newAgent.cpp \
    Sources/newCustomer.cpp \
    Sources/confirmDelete.cpp

HEADERS += Headers/agent.h \
    Headers/agentList.h \
    Headers/agentNode.h \
    Headers/callSystemMenu.h \
    Headers/confirmDeleteAll.h \
    Headers/customerUi.h \
    Headers/customer.h \
    Headers/customerList.h \
    Headers/customerNode.h \
    Headers/date.h \
    Headers/duration.h \
    Headers/editDuration.h \
    Headers/start.h \
    Headers/newAgent.h \
    Headers/newCustomer.h \
    Headers/confirmDelete.h

FORMS += \
    Forms/confirmDeleteAll.ui \
    Forms/editDuration.ui \
    Forms/start.ui \
    Forms/callSystemMenu.ui \
    Forms/customerUi.ui \
    Forms/newAgent.ui \
    Forms/newCustomer.ui \
    Forms/confirmDelete.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2017-11-20T18:39:34
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    clientwidget.cpp \
    findpassword.cpp \
    logindialog.cpp \
    main.cpp \
    register.cpp \
    sendfile.cpp \
    user_imformation.cpp

HEADERS  += \
    clientwidget.h \
    findpassword.h \
    logindialog.h \
    register.h \
    sendfile.h \
    user_imformation.h

RESOURCES += \
    src.qrc

FORMS += \
    clientwidget.ui \
    findpassword.ui \
    logindialog.ui \
    register.ui \
    sendfile.ui

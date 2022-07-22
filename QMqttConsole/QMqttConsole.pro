#-------------------------------------------------
#
# Project created by QtCreator 2022-05-30T19:07:49
#
#-------------------------------------------------

QT       += core network gui
QT += widgets
TARGET = QMqttConsole
#CONFIG   += console
CONFIG   -= app_bundle


CONFIG += c++11

TEMPLATE = app
QMAKE_LFLAGS += -Wl,-z,origin,-rpath=../lib

SOURCES += main.cpp \
    widget.cpp \
    gcslog.cpp

HEADERS += \
    widget.h \
    lib/include/qmqtt.h \
    lib/include/qmqtt_client.h \
    lib/include/qmqtt_client_p.h \
    lib/include/qmqtt_frame.h \
    lib/include/qmqtt_global.h \
    lib/include/qmqtt_message.h \
    lib/include/qmqtt_message_p.h \
    include/HCNetSDK.h \
    include/hikApi.h

INCLUDEPATH += lib/include \
                include \
                lib/HCNetSDKCom

LIBS += -L/$$PWD/lib \
        -lQt5Qmqtt \
        -lhcnetsdk \
        -lAudioRender\
        -lcrypto \
        -lHCCore \
        -lhpr\
        -lNPQos \
        -lPlayCtrl \
        -lssl \
        -lSuperRender \
        -lhikApi

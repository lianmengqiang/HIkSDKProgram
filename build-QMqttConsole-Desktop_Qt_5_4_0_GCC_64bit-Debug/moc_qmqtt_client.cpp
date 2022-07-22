/****************************************************************************
** Meta object code from reading C++ file 'qmqtt_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QMqttConsole/lib/include/qmqtt_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmqtt_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMQTT__Client_t {
    QByteArrayData data[86];
    char stringdata[1038];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMQTT__Client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMQTT__Client_t qt_meta_stringdata_QMQTT__Client = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QMQTT::Client"
QT_MOC_LITERAL(1, 14, 9), // "connected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "disconnected"
QT_MOC_LITERAL(4, 38, 5), // "error"
QT_MOC_LITERAL(5, 44, 18), // "QMQTT::ClientError"
QT_MOC_LITERAL(6, 63, 10), // "subscribed"
QT_MOC_LITERAL(7, 74, 5), // "topic"
QT_MOC_LITERAL(8, 80, 3), // "qos"
QT_MOC_LITERAL(9, 84, 12), // "unsubscribed"
QT_MOC_LITERAL(10, 97, 9), // "published"
QT_MOC_LITERAL(11, 107, 14), // "QMQTT::Message"
QT_MOC_LITERAL(12, 122, 7), // "message"
QT_MOC_LITERAL(13, 130, 5), // "msgid"
QT_MOC_LITERAL(14, 136, 8), // "received"
QT_MOC_LITERAL(15, 145, 8), // "pingresp"
QT_MOC_LITERAL(16, 154, 9), // "sslErrors"
QT_MOC_LITERAL(17, 164, 16), // "QList<QSslError>"
QT_MOC_LITERAL(18, 181, 6), // "errors"
QT_MOC_LITERAL(19, 188, 7), // "setHost"
QT_MOC_LITERAL(20, 196, 12), // "QHostAddress"
QT_MOC_LITERAL(21, 209, 4), // "host"
QT_MOC_LITERAL(22, 214, 11), // "setHostName"
QT_MOC_LITERAL(23, 226, 8), // "hostName"
QT_MOC_LITERAL(24, 235, 7), // "setPort"
QT_MOC_LITERAL(25, 243, 4), // "port"
QT_MOC_LITERAL(26, 248, 11), // "setClientId"
QT_MOC_LITERAL(27, 260, 8), // "clientId"
QT_MOC_LITERAL(28, 269, 11), // "setUsername"
QT_MOC_LITERAL(29, 281, 8), // "username"
QT_MOC_LITERAL(30, 290, 11), // "setPassword"
QT_MOC_LITERAL(31, 302, 8), // "password"
QT_MOC_LITERAL(32, 311, 10), // "setVersion"
QT_MOC_LITERAL(33, 322, 11), // "MQTTVersion"
QT_MOC_LITERAL(34, 334, 7), // "version"
QT_MOC_LITERAL(35, 342, 12), // "setKeepAlive"
QT_MOC_LITERAL(36, 355, 9), // "keepAlive"
QT_MOC_LITERAL(37, 365, 15), // "setCleanSession"
QT_MOC_LITERAL(38, 381, 12), // "cleanSession"
QT_MOC_LITERAL(39, 394, 16), // "setAutoReconnect"
QT_MOC_LITERAL(40, 411, 5), // "value"
QT_MOC_LITERAL(41, 417, 24), // "setAutoReconnectInterval"
QT_MOC_LITERAL(42, 442, 21), // "autoReconnectInterval"
QT_MOC_LITERAL(43, 464, 12), // "setWillTopic"
QT_MOC_LITERAL(44, 477, 9), // "willTopic"
QT_MOC_LITERAL(45, 487, 10), // "setWillQos"
QT_MOC_LITERAL(46, 498, 7), // "willQos"
QT_MOC_LITERAL(47, 506, 13), // "setWillRetain"
QT_MOC_LITERAL(48, 520, 10), // "willRetain"
QT_MOC_LITERAL(49, 531, 14), // "setWillMessage"
QT_MOC_LITERAL(50, 546, 11), // "willMessage"
QT_MOC_LITERAL(51, 558, 13), // "connectToHost"
QT_MOC_LITERAL(52, 572, 18), // "disconnectFromHost"
QT_MOC_LITERAL(53, 591, 9), // "subscribe"
QT_MOC_LITERAL(54, 601, 11), // "unsubscribe"
QT_MOC_LITERAL(55, 613, 7), // "publish"
QT_MOC_LITERAL(56, 621, 15), // "ignoreSslErrors"
QT_MOC_LITERAL(57, 637, 18), // "onNetworkConnected"
QT_MOC_LITERAL(58, 656, 21), // "onNetworkDisconnected"
QT_MOC_LITERAL(59, 678, 17), // "onNetworkReceived"
QT_MOC_LITERAL(60, 696, 12), // "QMQTT::Frame"
QT_MOC_LITERAL(61, 709, 5), // "frame"
QT_MOC_LITERAL(62, 715, 14), // "onTimerPingReq"
QT_MOC_LITERAL(63, 730, 13), // "onPingTimeout"
QT_MOC_LITERAL(64, 744, 14), // "onNetworkError"
QT_MOC_LITERAL(65, 759, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(66, 788, 11), // "onSslErrors"
QT_MOC_LITERAL(67, 800, 5), // "_port"
QT_MOC_LITERAL(68, 806, 5), // "_host"
QT_MOC_LITERAL(69, 812, 9), // "_hostName"
QT_MOC_LITERAL(70, 822, 9), // "_clientId"
QT_MOC_LITERAL(71, 832, 9), // "_username"
QT_MOC_LITERAL(72, 842, 9), // "_password"
QT_MOC_LITERAL(73, 852, 10), // "_keepAlive"
QT_MOC_LITERAL(74, 863, 8), // "_version"
QT_MOC_LITERAL(75, 872, 14), // "_autoReconnect"
QT_MOC_LITERAL(76, 887, 22), // "_autoReconnectInterval"
QT_MOC_LITERAL(77, 910, 13), // "_cleanSession"
QT_MOC_LITERAL(78, 924, 10), // "_willTopic"
QT_MOC_LITERAL(79, 935, 8), // "_willQos"
QT_MOC_LITERAL(80, 944, 11), // "_willRetain"
QT_MOC_LITERAL(81, 956, 12), // "_willMessage"
QT_MOC_LITERAL(82, 969, 16), // "_connectionState"
QT_MOC_LITERAL(83, 986, 15), // "ConnectionState"
QT_MOC_LITERAL(84, 1002, 17), // "_sslConfiguration"
QT_MOC_LITERAL(85, 1020, 17) // "QSslConfiguration"

    },
    "QMQTT::Client\0connected\0\0disconnected\0"
    "error\0QMQTT::ClientError\0subscribed\0"
    "topic\0qos\0unsubscribed\0published\0"
    "QMQTT::Message\0message\0msgid\0received\0"
    "pingresp\0sslErrors\0QList<QSslError>\0"
    "errors\0setHost\0QHostAddress\0host\0"
    "setHostName\0hostName\0setPort\0port\0"
    "setClientId\0clientId\0setUsername\0"
    "username\0setPassword\0password\0setVersion\0"
    "MQTTVersion\0version\0setKeepAlive\0"
    "keepAlive\0setCleanSession\0cleanSession\0"
    "setAutoReconnect\0value\0setAutoReconnectInterval\0"
    "autoReconnectInterval\0setWillTopic\0"
    "willTopic\0setWillQos\0willQos\0setWillRetain\0"
    "willRetain\0setWillMessage\0willMessage\0"
    "connectToHost\0disconnectFromHost\0"
    "subscribe\0unsubscribe\0publish\0"
    "ignoreSslErrors\0onNetworkConnected\0"
    "onNetworkDisconnected\0onNetworkReceived\0"
    "QMQTT::Frame\0frame\0onTimerPingReq\0"
    "onPingTimeout\0onNetworkError\0"
    "QAbstractSocket::SocketError\0onSslErrors\0"
    "_port\0_host\0_hostName\0_clientId\0"
    "_username\0_password\0_keepAlive\0_version\0"
    "_autoReconnect\0_autoReconnectInterval\0"
    "_cleanSession\0_willTopic\0_willQos\0"
    "_willRetain\0_willMessage\0_connectionState\0"
    "ConnectionState\0_sslConfiguration\0"
    "QSslConfiguration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMQTT__Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
      17,  328, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  219,    2, 0x06 /* Public */,
       3,    0,  220,    2, 0x06 /* Public */,
       4,    1,  221,    2, 0x06 /* Public */,
       6,    2,  224,    2, 0x06 /* Public */,
       6,    1,  229,    2, 0x26 /* Public | MethodCloned */,
       9,    1,  232,    2, 0x06 /* Public */,
      10,    2,  235,    2, 0x06 /* Public */,
      10,    1,  240,    2, 0x26 /* Public | MethodCloned */,
      14,    1,  243,    2, 0x06 /* Public */,
      15,    0,  246,    2, 0x06 /* Public */,
      16,    1,  247,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  250,    2, 0x0a /* Public */,
      22,    1,  253,    2, 0x0a /* Public */,
      24,    1,  256,    2, 0x0a /* Public */,
      26,    1,  259,    2, 0x0a /* Public */,
      28,    1,  262,    2, 0x0a /* Public */,
      30,    1,  265,    2, 0x0a /* Public */,
      32,    1,  268,    2, 0x0a /* Public */,
      35,    1,  271,    2, 0x0a /* Public */,
      37,    1,  274,    2, 0x0a /* Public */,
      39,    1,  277,    2, 0x0a /* Public */,
      41,    1,  280,    2, 0x0a /* Public */,
      43,    1,  283,    2, 0x0a /* Public */,
      45,    1,  286,    2, 0x0a /* Public */,
      47,    1,  289,    2, 0x0a /* Public */,
      49,    1,  292,    2, 0x0a /* Public */,
      51,    0,  295,    2, 0x0a /* Public */,
      52,    0,  296,    2, 0x0a /* Public */,
      53,    2,  297,    2, 0x0a /* Public */,
      53,    1,  302,    2, 0x2a /* Public | MethodCloned */,
      54,    1,  305,    2, 0x0a /* Public */,
      55,    1,  308,    2, 0x0a /* Public */,
      56,    0,  311,    2, 0x0a /* Public */,
      56,    1,  312,    2, 0x0a /* Public */,
      57,    0,  315,    2, 0x09 /* Protected */,
      58,    0,  316,    2, 0x09 /* Protected */,
      59,    1,  317,    2, 0x09 /* Protected */,
      62,    0,  320,    2, 0x09 /* Protected */,
      63,    0,  321,    2, 0x09 /* Protected */,
      64,    1,  322,    2, 0x09 /* Protected */,
      66,    1,  325,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UChar,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 11, QMetaType::UShort,   12,   13,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::UShort,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QByteArray,   31,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void, QMetaType::UShort,   36,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::UChar,   46,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, QMetaType::QByteArray,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UChar,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::UShort, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 65,    4,
    QMetaType::Void, 0x80000000 | 17,   18,

 // properties: name, type, flags
      67, QMetaType::UShort, 0x00095003,
      68, 0x80000000 | 20, 0x0009500b,
      69, QMetaType::QString, 0x00095003,
      70, QMetaType::QString, 0x00095003,
      71, QMetaType::QString, 0x00095003,
      72, QMetaType::QByteArray, 0x00095003,
      73, QMetaType::UShort, 0x00095003,
      74, 0x80000000 | 33, 0x0009500b,
      75, QMetaType::Bool, 0x00095003,
      76, QMetaType::Int, 0x00095003,
      77, QMetaType::Bool, 0x00095003,
      78, QMetaType::QString, 0x00095003,
      79, QMetaType::UChar, 0x00095003,
      80, QMetaType::Bool, 0x00095003,
      81, QMetaType::QByteArray, 0x00095003,
      82, 0x80000000 | 83, 0x00095009,
      84, 0x80000000 | 85, 0x0009500b,

       0        // eod
};

void QMQTT::Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->error((*reinterpret_cast< const QMQTT::ClientError(*)>(_a[1]))); break;
        case 3: _t->subscribed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint8(*)>(_a[2]))); break;
        case 4: _t->subscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->unsubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->published((*reinterpret_cast< const QMQTT::Message(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 7: _t->published((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        case 8: _t->received((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        case 9: _t->pingresp(); break;
        case 10: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 11: _t->setHost((*reinterpret_cast< const QHostAddress(*)>(_a[1]))); break;
        case 12: _t->setHostName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setPort((*reinterpret_cast< const quint16(*)>(_a[1]))); break;
        case 14: _t->setClientId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setUsername((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setPassword((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 17: _t->setVersion((*reinterpret_cast< const MQTTVersion(*)>(_a[1]))); break;
        case 18: _t->setKeepAlive((*reinterpret_cast< const quint16(*)>(_a[1]))); break;
        case 19: _t->setCleanSession((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 20: _t->setAutoReconnect((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 21: _t->setAutoReconnectInterval((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 22: _t->setWillTopic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->setWillQos((*reinterpret_cast< const quint8(*)>(_a[1]))); break;
        case 24: _t->setWillRetain((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 25: _t->setWillMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 26: _t->connectToHost(); break;
        case 27: _t->disconnectFromHost(); break;
        case 28: _t->subscribe((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint8(*)>(_a[2]))); break;
        case 29: _t->subscribe((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->unsubscribe((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: { quint16 _r = _t->publish((*reinterpret_cast< const QMQTT::Message(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = _r; }  break;
        case 32: _t->ignoreSslErrors(); break;
        case 33: _t->ignoreSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 34: _t->onNetworkConnected(); break;
        case 35: _t->onNetworkDisconnected(); break;
        case 36: _t->onNetworkReceived((*reinterpret_cast< const QMQTT::Frame(*)>(_a[1]))); break;
        case 37: _t->onTimerPingReq(); break;
        case 38: _t->onPingTimeout(); break;
        case 39: _t->onNetworkError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 40: _t->onSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::ClientError >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::connected)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::disconnected)) {
                *result = 1;
            }
        }
        {
            typedef void (Client::*_t)(const QMQTT::ClientError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::error)) {
                *result = 2;
            }
        }
        {
            typedef void (Client::*_t)(const QString & , const quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::subscribed)) {
                *result = 3;
            }
        }
        {
            typedef void (Client::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::unsubscribed)) {
                *result = 5;
            }
        }
        {
            typedef void (Client::*_t)(const QMQTT::Message & , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::published)) {
                *result = 6;
            }
        }
        {
            typedef void (Client::*_t)(const QMQTT::Message & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::received)) {
                *result = 8;
            }
        }
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::pingresp)) {
                *result = 9;
            }
        }
        {
            typedef void (Client::*_t)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::sslErrors)) {
                *result = 10;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSslConfiguration >(); break;
        }
    }

}

const QMetaObject QMQTT::Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMQTT__Client.data,
      qt_meta_data_QMQTT__Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMQTT::Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMQTT::Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMQTT__Client.stringdata))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int QMQTT::Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< quint16*>(_v) = port(); break;
        case 1: *reinterpret_cast< QHostAddress*>(_v) = host(); break;
        case 2: *reinterpret_cast< QString*>(_v) = hostName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = clientId(); break;
        case 4: *reinterpret_cast< QString*>(_v) = username(); break;
        case 5: *reinterpret_cast< QByteArray*>(_v) = password(); break;
        case 6: *reinterpret_cast< quint16*>(_v) = keepAlive(); break;
        case 7: *reinterpret_cast< MQTTVersion*>(_v) = version(); break;
        case 8: *reinterpret_cast< bool*>(_v) = autoReconnect(); break;
        case 9: *reinterpret_cast< int*>(_v) = autoReconnectInterval(); break;
        case 10: *reinterpret_cast< bool*>(_v) = cleanSession(); break;
        case 11: *reinterpret_cast< QString*>(_v) = willTopic(); break;
        case 12: *reinterpret_cast< quint8*>(_v) = willQos(); break;
        case 13: *reinterpret_cast< bool*>(_v) = willRetain(); break;
        case 14: *reinterpret_cast< QByteArray*>(_v) = willMessage(); break;
        case 15: *reinterpret_cast< ConnectionState*>(_v) = connectionState(); break;
        case 16: *reinterpret_cast< QSslConfiguration*>(_v) = sslConfiguration(); break;
        default: break;
        }
        _id -= 17;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPort(*reinterpret_cast< quint16*>(_v)); break;
        case 1: setHost(*reinterpret_cast< QHostAddress*>(_v)); break;
        case 2: setHostName(*reinterpret_cast< QString*>(_v)); break;
        case 3: setClientId(*reinterpret_cast< QString*>(_v)); break;
        case 4: setUsername(*reinterpret_cast< QString*>(_v)); break;
        case 5: setPassword(*reinterpret_cast< QByteArray*>(_v)); break;
        case 6: setKeepAlive(*reinterpret_cast< quint16*>(_v)); break;
        case 7: setVersion(*reinterpret_cast< MQTTVersion*>(_v)); break;
        case 8: setAutoReconnect(*reinterpret_cast< bool*>(_v)); break;
        case 9: setAutoReconnectInterval(*reinterpret_cast< int*>(_v)); break;
        case 10: setCleanSession(*reinterpret_cast< bool*>(_v)); break;
        case 11: setWillTopic(*reinterpret_cast< QString*>(_v)); break;
        case 12: setWillQos(*reinterpret_cast< quint8*>(_v)); break;
        case 13: setWillRetain(*reinterpret_cast< bool*>(_v)); break;
        case 14: setWillMessage(*reinterpret_cast< QByteArray*>(_v)); break;
        case 16: setSslConfiguration(*reinterpret_cast< QSslConfiguration*>(_v)); break;
        default: break;
        }
        _id -= 17;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMQTT::Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QMQTT::Client::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QMQTT::Client::error(const QMQTT::ClientError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMQTT::Client::subscribed(const QString & _t1, const quint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void QMQTT::Client::unsubscribed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QMQTT::Client::published(const QMQTT::Message & _t1, quint16 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void QMQTT::Client::received(const QMQTT::Message & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QMQTT::Client::pingresp()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void QMQTT::Client::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE

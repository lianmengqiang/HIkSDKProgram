#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <qmqtt.h>
//#include "lib/include/qmqtt.h"
#include "include/HCNetSDK.h"
#include "include/hikApi.h"
#include <unistd.h>
#include <QSettings>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QTime>
#include <QHash>
#include <QFrame>
#define CFG_PATH "./cfg.ini"

struct CAMERA_INFO{
    QString ip;
    int port;
    QString name;
    QString pwd;
    int UserID;
    BYTE chan;
};

class Widget: public QObject
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitWidget();

    //void clientMqtt();
private:
    void SendReload(QByteArray arr);
    void LogInit();
    void SendReloadJson(QString ip, int port, BYTE chan, QByteArray arr);
    QByteArray ImageToBase64(QString image);
    QPixmap Base64ToImage(QByteArray byteArray, QString savePath);
    bool AnalysisDate(QString mes, QString &ip, int &port, QString& name, QString &pwd);

    bool AnalysisStruDate(QByteArray arr, QList<CAMERA_INFO> &list);

    //out：错误码 0没有错误  1用户名密码错误 2权限不足  3没有初始化  4通道号错误  5连接到DVR的客户端个数超过最大
    //7连接服务器失败  8向服务器发送失败 28DVR资源不足  29DVR操作失败
    int InPictureCapture(char* ip, int port, char* name, char* pwd, char* path, int &lUserID, BYTE &chan);
    int DireatPictureCapture(CAMERA_INFO info,char *path);

    int InPlayPictureCapture(char* ip, int port, char* name, char* pwd, char* path, int &lUserID, BYTE &chan);


private:
    QMQTT::Client *client;

    QMQTT::Client *clientSend;

    QTimer *pTimer;

    QString publicTheme;
    QString subTheme;
    HWND                m_hPlayWnd;
    QFrame *frame;
    QList<CAMERA_INFO> list;
    QHash<QString, CAMERA_INFO> m_CAMERA_INFOHash;

private slots:
    void slotMQTT_Received(QMQTT::Message);

};

#endif // WIDGET_H

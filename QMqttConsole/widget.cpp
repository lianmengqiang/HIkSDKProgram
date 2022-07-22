#include <QObject>
#include "widget.h"
#include <QTimer>
#include <QString>
#include <QBuffer>
#include <sstream>
#include <time.h>
#include "gcslog.h"

Widget::Widget(QWidget *parent):
    client(nullptr),
    clientSend(nullptr),
    pTimer(new QTimer),
    publicTheme(""),
    subTheme(""),
    frame(new QFrame)

{
    m_CAMERA_INFOHash.clear();
    LogInit();

    //InitWidget();
    //clientMqtt();
}

Widget::~Widget()
{  
    client->unsubscribe(subTheme);
    if(client->isConnectedToHost()){
        client->unsubscribe(subTheme);
        client->disconnectFromHost();
    }
    if(client != nullptr){
        delete client;
        client = nullptr;
    }

    if(clientSend->isConnectedToHost()){
        clientSend->disconnectFromHost();
    }
    if(clientSend != nullptr){
        delete clientSend;
        clientSend = nullptr;
    }
    foreach (CAMERA_INFO info, m_CAMERA_INFOHash) {
        NET_DVR_Logout(info.UserID);
    }
    m_CAMERA_INFOHash.clear();

    if(pTimer->isActive()){
        pTimer->stop();
        delete pTimer;
        pTimer = NULL;
    }
    delete frame;
    frame = NULL;
}


void Widget::InitWidget()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    QString sIp = set.value("/Service/IP").toString();
    QString sPort = set.value("/Service/Port").toString();
    QString sName = set.value("/Service/UserName").toString();
    QString spwd = set.value("/Service/PassWord").toString();
    QString sID = set.value("/Service/DeviceID").toString();
    QString sSendID = set.value("/Service/SendDeviceID").toString();
    QString sAlive = set.value("/Service/Alive").toString();

    publicTheme = set.value("/Service/PublicTheme").toString();
    subTheme = set.value("/Service/SubTheme").toString();

    qDebug()<<sIp<<" "<<sPort<<"  "<<sName<<"  "<<spwd<<"  "<<sID<<"  "<<sAlive;

    //RecClient
    client = new QMQTT::Client();
    connect(client, SIGNAL(received(QMQTT::Message)), this, SLOT(slotMQTT_Received(QMQTT::Message)));

    QHostAddress host(sIp); //106.14.186.206
    QByteArray passwd = spwd.toUtf8(); //admin
    quint16 port = sPort.toInt();  //1883
    QString deviceid = sID;  //1234
    //QString productid = ui->led_ID->text();  // 1
    quint16 alive = sAlive.toInt();      //120
    QString username = sName;  //"admin"

    client->setKeepAlive(alive);  //120
    //client->setAutoReconnect(true);
    client->setHost(host);
    client->setPort(port);
    client->setClientId(deviceid);
    client->setUsername(username);
    client->setPassword(passwd);
    client->cleanSession();
    client->setVersion(QMQTT::MQTTVersion::V3_1_1);
    client->connectToHost();




    //SendClient4
    clientSend = new QMQTT::Client();
    //QString sendid = "1000";  //1000
    clientSend->setKeepAlive(alive);  //120
    clientSend->setHost(host);
    clientSend->setPort(port);
    clientSend->setClientId(sSendID);
    clientSend->setUsername(username);
    clientSend->setPassword(passwd);
    clientSend->cleanSession();
    clientSend->setVersion(QMQTT::MQTTVersion::V3_1_1);
    clientSend->connectToHost();

    QTimer::singleShot(100, this, [=](){
        client->subscribe(subTheme,0);
    });

}

void Widget::SendReload(QByteArray arr)
{
    if(!client->isConnectedToHost()){
        qDebug()<<"@@@@@@@@@@ Publish fail @@@@@@@@@@";
        return;
    }
    QString topic = publicTheme.trimmed();
    QMQTT::Message mes;
    mes.setTopic(topic);
    mes.setPayload(arr);
    //mes.setPayload(payload.toUtf8());
    client->publish(mes);
    qDebug()<<"@@@@@@@@@@ Publish success @@@@@@@@@@";
}

void Widget::LogInit()
{
    QDir dir;
    if(false == dir.exists("log")){
        if(false == dir.mkpath("log")){
            qDebug()<<"make log dir error!";
            return;
        }
    }
    qInstallMessageHandler(gcsMessageOutput);
}

void Widget::SendReloadJson(QString ip, int port,BYTE chan, QByteArray arr)
{

    if(!clientSend->isConnectedToHost()){
        qDebug()<<"@@@@@@@@@@ Publish fail @@@@@@@@@@";
        return;
    }
    QString strTimer = QTime::currentTime().toString("hh:mm:ss");
    QJsonObject obj1;
    obj1.insert("cameraIp", ip);
    obj1.insert("cameraPort", QString("%1").arg(port));
    obj1.insert("cameraPChannel", QString("%1").arg(chan));
    obj1.insert("pictureBase64", QJsonValue::fromVariant(arr));
    obj1.insert("timeStamp", strTimer);
    QJsonDocument document;
    document.setObject(obj1);
    QByteArray load = document.toJson(QJsonDocument::Compact);



    QString topic = publicTheme.trimmed();
    QMQTT::Message mes;
    mes.setTopic(topic);
    mes.setPayload(load);
    qDebug()<<"Payload Sizeof:"<<load.size();
    clientSend->publish(mes);
    //clientSend->publish(mes);
    QString str = QTime::currentTime().toString("hh_mm_ss_zzz");
    qDebug()<<"["<<str<<"]: @@@@@@@@@@ Publish success @@@@@@@@@@\n"<<endl;
}

void Widget::slotMQTT_Received(QMQTT::Message mes)
{
    list.clear();
    /*
    QString picturePath = "./PictureSave";
    QDir dir(picturePath);
    if(dir.exists()){
        dir.removeRecursively();
    }
    dir.mkpath(picturePath);*/

    QString str = mes.payload();
    QString strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
    qDebug()<<"["<<strTimer<<"]  Rec:"<<str;
    QString ip = "";
    QString name = "";
    QString pwd = "";
    int port = 0;

    if(!AnalysisStruDate(mes.payload(), list)){
        return;
    }

    foreach (CAMERA_INFO info, list) {
        strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
        qDebug()<<"["<<strTimer<<"]  Mess IP:"<<info.ip<<"  Port:"<<info.port<<"  Name:"<<info.name<<"  PWD:"<<info.pwd <<"  Channel:"<<info.chan;
        QString da = QDateTime::currentDateTime().toString("hhmmss");
        QString path1 = "./Picture/" + da +".jpg";
        std::string path = path1.toStdString();

        /*
        if(0 != pictureCapture((char*)ip.toStdString().c_str(), port, (char*)name.toStdString().c_str(), (char*)pwd.toStdString().c_str(), (char*)path.c_str())){
            return;
        }*/
        strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
        qDebug()<<"["<<strTimer<<"]  pictrue begin";

        //alread linking no ReLink
        /*
        if(!m_CAMERA_INFOHash.contains(info.ip)) {
            qDebug()<<"["<<strTimer<<"]  Carmera Info Login"<<info.ip<<"  Port:"<<info.port <<"  Channel:"<<info.chan;
            if(0 != InPictureCapture((char*)info.ip.toStdString().c_str(), info.port, (char*)info.name.toStdString().c_str(),
                                     (char*)info.pwd.toStdString().c_str(), (char*)path.c_str(), info.UserID, info.chan)){
                //path1 = "./Picture/re.bmp";
                qDebug()<<"Piture fail:";
                QByteArray ar = 00;
                //QString strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
                //qDebug()<<"["<<strTimer<<"]: @@@@@@@@@@ Publish begin @@@@@@@@@@";
                SendReloadJson(info.ip, info.port, info.chan, ar);
                continue;
            }
            m_CAMERA_INFOHash.insert(info.ip, info);
        } else {
            //update alread connect info , disconnect after connect
            if(m_CAMERA_INFOHash[info.ip].port != info.port) {
                NET_DVR_Logout(info.UserID);
                qDebug()<<"["<<strTimer<<"]  Carmera Info ReLogin"<<info.ip<<"  Port:"<<info.port <<"  Channel:"<<info.chan;
                if(0 != InPictureCapture((char*)info.ip.toStdString().c_str(), info.port, (char*)info.name.toStdString().c_str(),
                                         (char*)info.pwd.toStdString().c_str(), (char*)path.c_str(), info.UserID, info.chan)){
                    //path1 = "./Picture/re.bmp";
                    qDebug()<<"Piture fail:";
                    QByteArray ar = 00;
                    //QString strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
                    //qDebug()<<"["<<strTimer<<"]: @@@@@@@@@@ Publish begin @@@@@@@@@@";
                    SendReloadJson(info.ip, info.port, info.chan, ar);
                    continue;
                }
                m_CAMERA_INFOHash[info.ip].port = info.port;
            } else {
                //alread connect direct picture
                m_CAMERA_INFOHash[info.ip].chan = info.chan;
                qDebug()<<"["<<strTimer<<"]  Carmera already Login IP:"<<m_CAMERA_INFOHash[info.ip].ip
                       <<"  Port:"<<m_CAMERA_INFOHash[info.ip].port <<"  Channel:"<<m_CAMERA_INFOHash[info.ip].chan;
                if(0 != DireatPictureCapture(m_CAMERA_INFOHash[info.ip],(char*)path.c_str())){
                    qDebug()<<"Piture fail:";
                    QByteArray ar = 00;
                    SendReloadJson(info.ip, info.port, info.chan, ar);
                    continue;
                }
            }
        }*/
        /*
        if(0 != InPictureCapture((char*)info.ip.toStdString().c_str(), info.port, (char*)info.name.toStdString().c_str(),
                                 (char*)info.pwd.toStdString().c_str(), (char*)path.c_str(), info.UserID, info.chan)){
            return;
        }*/
        if(0 != InPlayPictureCapture((char*)info.ip.toStdString().c_str(), info.port, (char*)info.name.toStdString().c_str(),
                                 (char*)info.pwd.toStdString().c_str(), (char*)path.c_str(), info.UserID, info.chan)){
            return;
        }

        strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
        qDebug()<<"["<<strTimer<<"]  pictrue End:";
        //path1 = "./Picture/re.bmp";
        QByteArray ar = ImageToBase64(path1);

        qDebug()<<"PitureBase64 Size(byte):"<<ar.size();

        //QString path2 = "/home/mone/code/demo/MuMqtt/build-QmqttDemo-Desktop_Qt_5_4_0_GCC_64bit-Debug/save/" + da +".bmp";
        //Base64ToImage(ar, path2);
        //QByteArray ar;
        //ar[0] = 0xff;
        //SendReload(ar);
        QString strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
        qDebug()<<"["<<strTimer<<"]: @@@@@@@@@@ Publish begin @@@@@@@@@@";
        SendReloadJson(info.ip, info.port, info.chan, ar);
        /*
        if(QFile::remove(path1)){
            qDebug()<<"["<<strTimer<<"]: Del PicTure Success";
        } else {
            qDebug()<<"["<<strTimer<<"]: Del PicTure fail";
        }*/
    }
}
QByteArray Widget::ImageToBase64(QString image)
{
    QImage im(image);
    QByteArray ar;
    QBuffer buf(&ar);
    im.save(&buf,"JPG",40);
    QByteArray hexed = ar.toBase64();
    buf.close();
    return hexed;
}

QPixmap Widget::Base64ToImage(QByteArray byteArray, QString savePath)
{
    QByteArray Re = QByteArray::fromBase64(byteArray);
    QBuffer buf(&Re);
    buf.open(QIODevice::WriteOnly);
    QPixmap im;
    im.loadFromData(Re);
    if(savePath != ""){
        im.save(savePath);
    }
    return im;
}
bool Widget::AnalysisDate(QString mes, QString &ip, int &port, QString &name, QString &pwd)
{
    QStringList list = mes.split(",");
    foreach (QString var, list) {
       QString key = var.trimmed().section(":",0,0).trimmed();
       QString value = var.trimmed().section(":",1,1);
       if(key == ""){
           continue;
       } else if (key == tr("cameraIp")){
           qDebug()<<"cameraIp";
           ip = value.trimmed();
       } else if (key == "cameraPort"){
           port = value.trimmed().toInt();
       } else if (key == "userName"){
           name = value;
       } else if (key == "passWord"){
           pwd = value;
       }
    }
    if((ip == "") || (name == "")|| (pwd == "") || (port == 0)){
        return false;
    } else {
        return true;
    }
}

bool Widget::AnalysisStruDate(QByteArray arr, QList<CAMERA_INFO> &list)
{
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(arr, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) { // 解析未发生错误
        if (doucment.isArray()) { // JSON 文档为数组
            QJsonArray array = doucment.array();  // 转化为数组
            int nSize = array.size();  // 获取数组大小

            for (int i = 0; i < nSize; ++i) {  // 遍历数组
                CAMERA_INFO camerInfo;
                QJsonValue value = array.at(i);
                if (value.isObject()) {  // Page 的 value 是对象
                    QJsonObject obj = value.toObject();
                    if (obj.contains("cameraIp")) {
                        QJsonValue value = obj.value("cameraIp");
                        if (value.isString()) {
                            camerInfo.ip = value.toString();
                            //qDebug() << "IP : " << strHome;
                        }
                    }
                    if (obj.contains("cameraPort")) {
                        QJsonValue value = obj.value("cameraPort");
                        if (value.isString()) {
                            //qDebug() << "Port : " << value.toString();
                            camerInfo.port = value.toString().toInt();
                        }
                    }
                    if (obj.contains("cameraChannel")) {
                        QJsonValue value = obj.value("cameraChannel");
                        if (value.isString()) {
                            qDebug() << "cameraChannel : " << value.toString();
                            camerInfo.chan = value.toString().toShort();
                        }
                    }
                    if (obj.contains("userName")) {
                        QJsonValue value = obj.value("userName");
                        if (value.isString()) {
                            camerInfo.name = value.toString();
                        }
                    }
                    if (obj.contains("passWord")) {
                        QJsonValue value = obj.value("passWord");
                        if (value.isString()) {
                            camerInfo.pwd = value.toString();
                        }
                    }
                }
                list.append(camerInfo);
            }
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}


int Widget::InPictureCapture(char *ip, int port, char *name, char *pwd, char *path, int &lUserID, BYTE &chan)
{
      QString strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
      qDebug()<<"["<<strTimer<<"]  NET_DVR_Init";
       //---------------------------------------
        // 初始化
        //printf("1. 设备初始化\n");
        NET_DVR_Init();
        //---------------------------------------
        // 注册设备
        //int lUserID;
        //设备信息, 输出参数
        //printf("4. 注册设备\n");
        //printf("ip:%s,port:%d,name:%s,pwd:%s\n",ip,port,name,pwd);
        NET_DVR_DEVICEINFO  m_deviceInfo;
        lUserID = NET_DVR_Login((char*)ip, port, (char*)name, (char*)pwd, &m_deviceInfo);
        strTimer = QTime::currentTime().toString("hh_mm_ss_zzz");
        qDebug()<<"["<<strTimer<<"]  NET_DVR_Login end: UserID:"<<lUserID;
        if (lUserID < 0)
        {
            //printf("Login failed, error code: %d\n", NET_DVR_GetLastError());
            NET_DVR_Cleanup();
            DWORD dwErrorCode = NET_DVR_GetLastError();
            qDebug()<<"Code:"<<dwErrorCode;
            return NET_DVR_NETWORK_FAIL_CONNECT;
        }
        int  iRet = 0;
        NET_DVR_JPEGPARA strPicPara;
        strPicPara.wPicQuality = 0;
        strPicPara.wPicSize = 0;
        //m_deviceInfo.byDVRType = 1;
        //m_deviceInfo.byChanNum = 35;
        m_deviceInfo.byStartChan = chan;
       // qDebug()<<"byStartChan:"<<(int)chan;
        iRet = NET_DVR_CaptureJPEGPicture(lUserID, m_deviceInfo.byStartChan, &strPicPara, (char *)path);

        if (!iRet)
        {
            //NET_DVR_NOERROR
            DWORD dwErrorCode = NET_DVR_GetLastError();
            qDebug()<<"PICCode:"<<dwErrorCode;
            return dwErrorCode;
        }
        usleep(10);  //0.2s  微妙500000 = 500毫秒
        /*
        //---------------------------------------
        //注销用户
        //printf("6. 注销用户\n");
        NET_DVR_Logout(lUserID);
        //释放SDK资源
        //printf("7. 释放SDK资源\n");
        NET_DVR_Cleanup();*/

        return NET_DVR_NOERROR;  //0
}

int Widget::DireatPictureCapture(CAMERA_INFO info, char *path)
{
    NET_DVR_JPEGPARA strPicPara;
    strPicPara.wPicQuality = 0;
    strPicPara.wPicSize = 0;
    int  iRet = NET_DVR_CaptureJPEGPicture(info.UserID, info.chan, &strPicPara, (char *)path);
    if (!iRet)
    {
        DWORD dwErrorCode = NET_DVR_GetLastError();
        return dwErrorCode;
    }
    return NET_DVR_NOERROR;
}

int Widget::InPlayPictureCapture(char *ip, int port, char *name, char *pwd, char *path, int &m_userID, BYTE &chan)
{

    DWORD   error = 0;
    NET_DVR_DEVICEINFO  m_deviceInfo;   //获取相机设备信息
    qDebug() << name << ", " << pwd << ", " << ip<<",  "<<port;
    NET_DVR_Init();
    m_userID = NET_DVR_Login(ip, port, name, pwd, &m_deviceInfo);
    if(m_userID < 0)
    {
        error = NET_DVR_GetLastError();
        qDebug()<< "connect() : NET_DVR_Login fail : m_userID < 0 m_isConnect = false error =" <<error;
        return error;
    }

    NET_DVR_SCALECFG  scaleCfg;
    if(NET_DVR_RemoteControl(m_userID,NET_DVR_CHECK_USER_STATUS,NULL,0) != TRUE)
    {
        qDebug()<< "connect() : NET_DVR_RemoteControl fail";
        return NET_DVR_NETWORK_FAIL_CONNECT;
    }
    //获取视频输出缩放信息。
    NET_DVR_GetScaleCFG_V30(m_userID, &scaleCfg);
    scaleCfg.dwMajorScale = 1;
    scaleCfg.dwMinorScale = 1;
    NET_DVR_SetScaleCFG_V30(m_userID, &scaleCfg);

    NET_DVR_PREVIEWINFO struPlayInfo;
    memset(&struPlayInfo, 0, sizeof(struPlayInfo));

    struPlayInfo.hPlayWnd     = frame->winId();         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = chan;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.byProtoType = 0;    //应用层取流协议，0-私有协议，1-RTSP协议
    struPlayInfo.byPreviewMode = 0;    //预览模式，0-正常预览，1-延迟预览
    struPlayInfo.byVideoCodingType = 0; //码流数据编解码类型 0-通用编码数据 1-热成像探测器产生的原始数据（温度数据的加密信息，通过去加密运算，将原始数据算出真实的温度值）
    struPlayInfo.dwDisplayBufNum = 50; //播放库播放缓冲区最大缓冲帧数，范围1-50，置0时默认为1
    LONG m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_userID, &struPlayInfo, NULL,NULL);

    if (m_lRealPlayHandle < 0)
    {
        qDebug()<< "startPlay() : m_lRealPlayHandle < 0 "<<m_lRealPlayHandle;
        //释放SDK资源
        NET_DVR_Cleanup();
        return NET_DVR_GetLastError();
    }

    // "D:\\test.bmp"   ="D:\\test.jpg"；
    if(NET_DVR_SetCapturePictureMode(JPEG_MODE) != TRUE){
        qDebug()<< "connect() : NET_DVR_SetCapturePictureMode fail";
        //释放SDK资源
        NET_DVR_Cleanup();
        return NET_DVR_MODIFY_FAIL;
    }
    qDebug()<< "connect() : NET_DVR_SetCapturePictureMode path:"<<path;

    int ret = NET_DVR_CapturePicture(m_lRealPlayHandle, path);
    if(ret < NET_DVR_NOERROR){
        qDebug()<< "connect() : NET_DVR_CapturePicture fail error"<<ret;
        //释放SDK资源
        NET_DVR_Cleanup();
        return NET_DVR_NETWORK_RECV_ERROR;
    }
    sleep(1);
     //---------------------------------------
     //关闭预览
    NET_DVR_StopRealPlay(m_lRealPlayHandle);
    //注销用户
    NET_DVR_Logout(m_userID);
    //释放SDK资源
    NET_DVR_Cleanup();


    return NET_DVR_NOERROR;

}


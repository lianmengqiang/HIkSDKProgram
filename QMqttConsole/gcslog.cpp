#include "gcslog.h"
#include <iostream>
#include <QDate>
#include <fstream>

static std::ofstream fLogFile;

void gcsMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString currentTime = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ");
    QString currentDate = currentTime.mid(1, 10);
#ifdef WIN32
    QString fileName = QString(context.file).section('\\', -1);
#else
    QString fileName = QString(context.file).section('/', -1);
#endif

    static QString lastDate = currentDate;
    QString level("");

    switch (type) {
    case QtDebugMsg:
        level = "Debug";
        break;
    case QtWarningMsg:
        level = "Warning";
        break;
    case QtCriticalMsg:
        level = "Critical";
        break;
    case QtFatalMsg:
        level = "Fatal";
        break;
    default:
        std::cout<<"unknown message type:"<<type<<std::endl;
        break;
    }

    QString message = currentTime  + "(" + level + ":" + fileName + ":" + QString::number(context.line, 10) + ") " + msg;

    std::cerr<<std::string(message.toLocal8Bit())<<std::endl;

    QString logPath = "log/gcsLog_" + currentDate + ".txt";
    if (false == fLogFile.is_open())
    {
        if (false == openLogFile(logPath))
        {
            return;
        }
    }
    else if (currentDate != lastDate)
    {
        if (false == openLogFile(logPath))
        {
            return;
        }
        lastDate = currentDate;
    }

    fLogFile<<std::string(message.toLocal8Bit())<<std::endl;
}

bool openLogFile(QString &rLogFilePathP)
{
    fLogFile.close();
    fLogFile.clear();
    fLogFile.open(rLogFilePathP.toStdString().c_str(), std::ios_base::app);
    if(false == fLogFile.is_open())
    {
       std::cout<<"open log file error, file path:"<<rLogFilePathP.toStdString()<<std::endl;
       return false;
    }

    return true;
}

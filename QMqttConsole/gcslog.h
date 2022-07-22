#ifndef GCS_LOG_H
#define GCS_LOG_H

#include <QFile>

void gcsMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
bool openLogFile(QString &rLogFilePathP);

#endif

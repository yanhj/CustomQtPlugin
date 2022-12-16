//********************************************************
/// @brief 日期输出插件
/// @author yanhuajian
/// @date 2021/10/3
/// @note
/// @version 1.0.0
//********************************************************

#include "DateEcho.h"
#include <QtCore/QDateTime>
#include <QtCore/QDebug>

void DateEcho::echo() {
    qInfo() << "DateEcho::echo() " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}
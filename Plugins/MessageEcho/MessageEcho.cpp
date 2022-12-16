//********************************************************
/// @brief 字符消息输出插件
/// @author yanhuajian
/// @date 2021/10/3
/// @note
/// @version 1.0.0
//********************************************************

#include "MessageEcho.h"
#include <QtCore/QDateTime>
#include <QtCore/QDebug>

void MessageEcho::echo() {
    qInfo() << "MessageEcho::echo() " << "Today is a great day!!!";
}
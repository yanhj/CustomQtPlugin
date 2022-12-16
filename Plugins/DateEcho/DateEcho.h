//********************************************************
/// @brief 日期输出插件
/// @author yanhuajian
/// @date 2021/10/3
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "../Interface/IEchoInterface.h"

class DateEcho : public QObject, public IEchoInterface {
    Q_OBJECT
    //插件信息
    Q_PLUGIN_METADATA(IID "com.yanhuajian.IEchoInterface" FILE "IEchoInterface.json")
    //插件接口
    Q_INTERFACES(IEchoInterface)
public:
    DateEcho() = default;
    virtual ~DateEcho() = default;

    virtual void echo() override;
};

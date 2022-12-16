//********************************************************
/// @brief 插件抽象接口
/// @author yanhuajian
/// @date 2021/10/3
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QObject>
class IEchoInterface {
public:
    IEchoInterface() = default;
    virtual ~IEchoInterface() = default;

    virtual void echo() = 0;
};

//插件抽象接口
QT_BEGIN_NAMESPACE

#define IEchoInterface_iid "com.yanhuajian.IEchoInterface"
Q_DECLARE_INTERFACE(IEchoInterface, IEchoInterface_iid)

QT_END_NAMESPACE

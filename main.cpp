//********************************************************
/// @brief 插件加载测试
/// @author yanhuajian
/// @date 2021/10/3
/// @note
/// @version 1.0.0
//********************************************************

#include <QtGui/QGuiApplication>
#include <QtCore/QDir>
#include <QtCore/QPluginLoader>
#include "Plugins/Interface/IEchoInterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    auto appPath = qApp->applicationDirPath() + "/plugins";
    qInfo() << "appPath: " << appPath;

    QDir dir(appPath);
    for(auto file : dir.entryInfoList({"*.dylib", "*.dll", "*.a"}, QDir::Files)) {
        //加载插件
        QPluginLoader loader(file.absoluteFilePath());
        if(loader.load()) {
            //获取插件对象
            auto plugin = loader.instance();
            if(plugin) {
                //获取插件接口
                auto echoInterface = qobject_cast<IEchoInterface*>(plugin);
                if(echoInterface) {
                    echoInterface->echo();
                }
            }
            loader.unload();
        } else {
            qWarning() << loader.errorString();
        }
    }

    return 0;
}
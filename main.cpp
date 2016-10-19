#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlEngine>
#include <music.h>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
        viewer.setMainQmlFile(QStringLiteral("qml/IcejellyMusic/main.qml"));
        viewer.showExpanded();
    qmlRegisterType<Music>("my.Music",1,0,"Music");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}

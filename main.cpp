#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include<QQmlEngine>
#include <music.h>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    qmlRegisterType<Music>("my.Music",1,0,"Music");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

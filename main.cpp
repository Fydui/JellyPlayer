#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlEngine>
#include <music.h>
#include <QCoreApplication>

QQmlApplicationEngine engine;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    qmlRegisterType<Music>("my.Music",1,0,"Music");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

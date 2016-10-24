#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlEngine>
#include <music.h>
#include <QCoreApplication>
QQmlApplicationEngine* engine;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    Music* a = new Music;
    a->ShowMusicList();
    QStringList dataList;
    int sum = 1;
    while(a->list[sum] != ""){
        //QString zhuan = QString::fromStdString(list[i]);
        dataList.append(a->list[sum]);
        sum++;
    }
    QQuickView view;
    QQmlContext* context  = view.rootContext();
    context->setContextProperty("myPlay",a);
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));

    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    a->play_pause();
    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlEngine>
#include <music.h>
#include <QCoreApplication>


extern vector<vector<QString>> list_;
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    Music* a = new Music;
    a->ShowMusicList();
    QQuickView* view = new QQuickView;
    QStringList dataList;   //显示列表
    int sum = 1;
    while(list_[0][sum] != ""){
        dataList.append(list_[0][sum]);
        sum++;
    }

    QStringList lrclist = a->showlrc("李白.mp3",00);
    QQmlContext* context  = view->rootContext();
    context->setContextProperty("myPlay",a);

    QQmlContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));

    QQmlContext* lrc = view->rootContext();
    lrc->setContextProperty("myLRC",QVariant::fromValue(lrclist));

    a->setview(view);


    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    //a->play_pause();
    return app.exec();
}

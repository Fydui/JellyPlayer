#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlEngine>
#include <music.h>
#include <QCoreApplication>
extern vector<vector<QString>> list_;
int main(int argc, char *argv[])
{
    //如果编译出的程序在其他机器上出现Failed to load platform plugin "windows" 则使用下段代码
    /*
    QTextCodec *xcodec = QTextCodec::codecForLocale() ;
        QString exeDir = xcodec->toUnicode( QByteArray(argv[0]) ) ;
        QString BKE_CURRENT_DIR = QFileInfo(exeDir).path() ;
        QStringList  libpath;
        libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/platforms");
        libpath << BKE_CURRENT_DIR <<BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/imageformats");
        libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins");
        //libpath << QApplication::libraryPaths();
        libpath << QCoreApplication::libraryPaths();
        QCoreApplication::setLibraryPaths(libpath) ;*/

    QGuiApplication app(argc, argv);
      Music* a = new Music;
      a->ShowMusicList();
      //QQuickView* view = new QQuickView;
      //QML界面文件需要使用QQmlApplicationEngine类型启动 所以一开始使用QQuick启动出现一闪而过的情况是这个原因
      QQmlApplicationEngine* view = new QQmlApplicationEngine;
      QStringList dataList;   //显示列表
      int sum = 1;
      while(list_[0][sum] != ""){
          dataList.append(list_[0][sum]);
          sum++;
      }
      QQmlContext* context  = view->rootContext();
      context->setContextProperty("myPlay",a);

      QQmlContext *ctxt = view->rootContext();
      ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
      a->setview(view);
      //view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
      view->load(QUrl(QStringLiteral("qrc:/main.qml")));
      return app.exec();
}

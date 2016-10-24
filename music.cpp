#include "music.h"

using namespace std;
extern  QQmlApplicationEngine* engine;
//QStringListModel model;

Music::Music(QObject *p):
    QObject(p)
{
    //
}

Music::~Music()
{
    delete now;
    //delete list;
}
void Music::ShowMusicList()
{

    QTextCodec* codec = QTextCodec::codecForName("GBK");
    qmlRegisterType<Music>("my.Music",1,0,"Music");
    engine = new QQmlApplicationEngine;
    _finddata_t file;
    int k,i = 0;
    long HANDLE;
    k = HANDLE = _findfirst( "music/*.mp3", &file );
    while( k != -1 ){
        QString str = codec->toUnicode(file.name);
        this->list[i+1] = str;
        k = _findnext( HANDLE, &file );
        i++;
    }
    _findclose( HANDLE );
    return;
}

void Music::startPlay(QString name)
{
    delete this->now; //把原来的删了
    this->now = new QMediaPlayer;
    //QObject::connect(now, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    this->now->setMedia(QUrl("E:/Code/cpp/IcejellyMusic/music/"+name));//相对路径
    for(int i = 1; i < 1001; i++){
        if(this->list[i] == name)
            tag = i;
    }
    this->now->setVolume(this->vol);
    this->now->play();
}

void Music::pausePlay(){

    if(this->k == false){
        this->now->pause();
        k=true;
    }
    else{
        this->now->play();
        k=false;
    }
}
void Music::VOL(int v){    
    this->now->setVolume(v);
}

void Music::lastMusic(){
    if(this->list[tag-1] != "")
        this->startPlay(this->list[tag-1]);
}

void Music::nextMusic(){
    if(this->list[tag+1]  != "")
        this->startPlay(this->list[tag+1]);

}
bool Music::MusicLoop(bool l){
    if(l)
        this->startPlay(this->list[tag]);
}

QQuickView* Music::ViewMusicList()
{
    QStringList dataList;
    int a = 1;
    while(this->list[a] != ""){
        //QString zhuan = QString::fromStdString(list[i]);
        dataList.append(this->list[a]);
        a++;
    }
    QQuickView* view;
    QQmlContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    return view;
}

void Music::test(QString a)
{
    this->startPlay(a);
}

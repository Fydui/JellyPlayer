#include "music.h"
using namespace std;
Music::Music(QObject *p):
    QObject(p)
{
    //
}

void Music::ShowMusicList()
{
    //const char* path_ = path.data();
    //const char* path_ = path.c_str();
    //QStringListModel model;
    QQmlContext* context  = new QQmlContext(engine.rootContext());
    context->setContextProperty("MUSIC_LIST",this);
    _finddata_t file;
     int k,i = 0;
     long HANDLE;
     k = HANDLE = _findfirst( "music/*.mp3", &file );
     while( k != -1 ){
      this->list[i+1] = file.name;
      k = _findnext( HANDLE, &file );
      i++;
     }

     _findclose( HANDLE );
     /*
    QQmlEngine engine;
    QStringListModel model;
    QStringList lis;
    QQmlContext* context  = new QQmlContext(engine.rootContext());
    context->setContextProperty("myModel",&model);
    QByteArray* da = new QByteArray;

    int i = 0;
    while(this->list[i] != ""){
        QString a = QString::number(list[i]);
        a = "List"
        da->append(a);
    }
    model.setStringList(list);
    QQmlComponent component(&engine);
    component.setData(da,QUrl());
    QObject *window = component.create(context);*/

     return;
}

void Music::StartPlay(string name)
{
    delete this->now; //把原来的删了
    QString name_ = QString::fromStdString(name);
    this->now = new QMediaPlayer;
    connect(this->now, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    this->now->setMedia(QUrl::fromLocalFile("music/"+name_+".mp3"));//相对路径
    for(int i = 1; i < 1001; i++){
        if(this->list[i] == name+".mp3")
            this->tag = i;
    }
    this->now->setVolume(this->vol);
    this->now->play();
}


void Music::PausePlay(){
    this->now->pause();
}

void Music::VOL(int v){
    this->now->setVolume(v);
}

void Music::LastMusic(){
    if(list[tag-1] != "")
     this->StartPlay(this->list[tag-1]);
}

void Music::NextMusic(){
    if(list[tag+1 != ""])
        this->StartPlay(this->list[tag+1]);
}
bool Music::MusicLoop(bool l){
    if(l)
        this->StartPlay(list[tag]);
}

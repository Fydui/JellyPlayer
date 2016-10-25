#include "music.h"
vector<vector<QString>> list_(1,vector<QString>(1));

using namespace std;
extern  QQmlApplicationEngine* engine;
//QStringListModel model;

Music::Music(QObject *p):
    QObject(p)
{

    //this->list(1,vector<QString>(1));
    this->playlist = NULL;
    this->now = NULL;
}

Music::~Music()
{
    delete now;
}
void Music::ShowMusicList()
{
    QTextCodec* codec = QTextCodec::codecForName("GBK");
    qmlRegisterType<Music>("my.Music",1,0,"Music");
    engine = new QQmlApplicationEngine;
    this->playlist = new QMediaPlaylist;
    _finddata_t file;
    int k,i = 1;
    long HANDLE;
    list_[0][0] = "";
    k = HANDLE = _findfirst( "music/*.mp3", &file );
    while( k != -1 ){
        QString str = codec->toUnicode(file.name);
        list_[0].push_back(str); //动态分配
        list_[0][i]= str;
        this->playlist->addMedia(QUrl("E:/Code/cpp/IcejellyMusic/music/"+str));
        k = _findnext( HANDLE, &file );
        i++;
    }
    list_[0].push_back("");
    list_[0][i] = "";

    _findclose( HANDLE );
    return;
}

void Music::startPlay(QString name)
{
    if(this->now != NULL)
        delete this->now; //把原来的删了

    this->now = new QMediaPlayer;
    this->now->setMedia(QUrl("E:/Code/cpp/IcejellyMusic/music/"+name));//相对路径
    this->now->setVolume(this->vol);

    for(int i = 1; i < sizeof(list_[0][i]); i++){
        if(list_[0][i] == name)
            this->tag = i;
    }

    this->playlist->setCurrentIndex(this->tag);
    this->now->setPlaylist(this->playlist);
    this->now->play();
}

void Music::pausePlay(){

    if(this->k == false && this->now != NULL){
        this->now->pause();
        k=true;
    }
    else if(this->k == true && this->now != NULL){
        this->now->play();
        k=false;
    }
}
void Music::setVol(int v){
    this->now->setVolume(v);
}

void Music::lastMusic(){
    if(list_[0][tag-1] != "" && this->now != NULL)
        this->startPlay(list_[0][tag-1]);
}

void Music::nextMusic(){
    if(list_[0][tag+1]  != "" && this->now != NULL)
        this->startPlay(list_[0][tag+1]);

}
bool Music::musicLoop(bool l){
    //if(l && )
      //  this->startPlay(list_[0][tag]);
}

QQuickView* Music::ViewMusicList()
{
    QStringList dataList;
    int a = 1;
    while(list_[0][a] != ""){
        //QString zhuan = QString::fromStdString(list[i]);
        dataList.append(list_[0][a]);
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

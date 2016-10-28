#include "music.h"
vector<vector<QString>> list_(1,vector<QString>(1));

using namespace std;
extern  QQmlApplicationEngine* engine;
//QStringListModel model;

Music::Music(QObject *p):
    QObject(p)
{
    this->now = new QMediaPlayer;
    this->playlist = new QMediaPlaylist;
}

Music::~Music()
{
    delete this->now;
    delete this->playlist;
    list_.clear();
}
void Music::ShowMusicList()
{
    QTextCodec* codec = QTextCodec::codecForName("GBK");
    qmlRegisterType<Music>("my.Music",1,0,"Music");

    _finddata_t file;
    int k,i = 1;
    long HANDLE;
    //list_[0][0] = "";
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
    if(this->now != NULL){

        for(int i = 0; i<sizeof(list_[0][0]); i++){ //遍历list_
            if(list_[0][i] == name){                //找到用户点击的那个是list_中的第几个(就是传进来的name)
                delete this->playlist;              //删除之前的playlist 重new一个
                this->playlist = new QMediaPlaylist;

                for(int j = i; j<sizeof(list_[0][0])+1;j++){ //从i开始 也就是用户点击的那个音乐(name)开始 往后构建播放列表 前面的不要了
                    this->playlist->addMedia(QUrl("E:/Code/cpp/IcejellyMusic/music/"+list_[0][j]));;
                }
                this->tag = i;                          //把标记设为当前音乐在list_中所处的位置 用于上下切歌
                delete this->now;                       //删除当前的音乐指针 重new一个
                this->now = new QMediaPlayer;
                this->playlist->setCurrentIndex(1);     //这函数我也不知道干啥的 有人说是设置当前音乐为第一个播放?
                this->now->setPlaylist(this->playlist); //对now指针 设置播放列表

                QObject::connect(now, &QMediaPlayer::positionChanged, [this](qint64 position){
                        if(this->now->duration() != 0)
                            this->endtime = this->now->duration();//获取当前音乐的总时长
                        this->time = position;          //获得当前播放的位置(就是当前播放到哪了 单位:毫秒)
                });

                this->setVol(80);                       //音量
                this->now->play();                      // Let's Play!
            }
        }


    }
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
        dataList.append(list_[0][a]);
        a++;
    }
    QQuickView* view;
    QQmlContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    return view;
}

void Music::setNowMusicPos(qint64 time)
{
//
}

void Music::test(QString a)
{
    this->startPlay(a);
}

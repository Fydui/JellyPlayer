#include "music.h"
vector<vector<QString>> list_(1,vector<QString>(1));
QTextCodec* codec = QTextCodec::codecForName("GBK");
extern  QQmlApplicationEngine* engine;
extern QQuickView* view;
using namespace std;
Music::Music(QObject *p):
    QObject(p)
{
    this->now = new QMediaPlayer;
    this->playlist = new QMediaPlaylist;
    this->LrcList.clear();
    this->timelist.clear();
}

Music::~Music()
{
    delete this->now;
    delete this->playlist;
    delete this->myView;
    this->LrcList.clear();
    this->timelist.clear();
    list_.clear();
}
void Music::ShowMusicList()
{
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
        this->playlist->addMedia(QUrl("music/"+str));
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
        for(int i = 0; i<list_[0].size(); i++){ //遍历list_
            if(list_[0][i] == name){                //找到用户点击的那个是list_中的第几个(就是传进来的name)
                delete this->playlist;              //删除之前的playlist 重new一个
                this->playlist = new QMediaPlaylist;

                for(int j = i; j<list_[0].size();j++){ //从i开始 也就是用户点击的那个音乐(name)开始 往后构建播放列表 前面的不要了
                    this->playlist->addMedia(QUrl("music/"+list_[0][j]));;
                }
                this->tag = i;                          //把标记设为当前音乐在list_中所处的位置 用于上下切歌
                delete this->now;                       //删除当前的音乐指针 重new一个
                this->now = new QMediaPlayer;
                this->playlist->setCurrentIndex(1);     //这函数我也不知道干啥的 有人说是设置当前音乐为第一个播放?
                this->now->setPlaylist(this->playlist); //对now指针 设置播放列表
                cleraLrcView(); //先把当前的歌词表清了
                QObject::connect(now, &QMediaPlayer::positionChanged, [this](qint64 position){
                    if(this->now->duration() != 0)
                        this->setEndtime(this->now->duration());  //获取当前音乐的总时长

                        this->settime(position);//获得当前播放的位置(就是当前播放到哪了 单位:毫秒)
                        QQmlContext* s_time = this->myView->rootContext();
                        s_time->setContextProperty("mySTIME",QVariant(this->timeformat(position)));

                        QQmlContext* now_progress = this->myView->rootContext();
                        now_progress->setContextProperty("setNOW",QVariant(position));
                        showlrc(this->getMusicTitle(),position);

                        QQmlContext* e_time  = this->myView->rootContext();
                        e_time->setContextProperty("myETIME",QVariant(this->timeformat(this->endtime)));

                        QQmlContext* title = this->myView->rootContext();
                        title->setContextProperty("myTITLE",QVariant(this->getMusicTitle()));

                });

                this->setVol(this->vol);                       //音量
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
    this->vol = v;
}

int Music::getVol(){return this->vol;}

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

void Music::setNowMusicPos(qint64 time){
    this->now->setPosition(time);
}

void Music::setview(QQmlApplicationEngine* v){
    this->myView = v;
}
/*
void Music::setview(QQuickView *view2){
    //this->myView = view2;
}*/
void Music::setEndtime(qint64 settime_){
    this->endtime = settime_;
}

qint64 Music::getEndtime(){return this->endtime;}

qint64 Music::endTime(){
    return this->endtime;
}

void Music::settime(qint64 time_){
    this->nowtime = time_;
}

qint64 Music::times(){
    return this->nowtime;
}

QString Music::timeformat(qint64 musictime){ //格式化时间 形参单位毫秒
    int min = musictime/1000/60;  //换算成分钟
    int sec = musictime/1000;     //换算成秒

    while(sec>=60)  sec = sec%60; //如果当前接受的时间大于等于60秒 除以60取其余数就是格式化的秒

    QString outtime = QString::number(min) + ":" + QString::number(sec);
    return outtime;
}

QString Music::getMusicTitle(){
    return list_[0][this->tag];
}

QString Music::getMusicTitle(QString name){
    return name;
}

QStringList Music::showlrc(QString name,qint64 time)
{
    if(this->LrcList.isEmpty()){                      //如果歌词表是空的
        const QRegExp rx("\\[(\\d+):(\\d+(\\.\\d+)?)\\]"); //用来查找时间标签的正则表达式
        QString name_ = name.section('.',0,0);
        QFile mylrc("music/"+name_+".lrc");
        if(!mylrc.open(QIODevice::ReadOnly | QIODevice::Text)) return this->LrcList;

        while(!mylrc.atEnd()){
            QString str = codec->toUnicode(mylrc.readLine());
            QString lrc = str.section("]",1,1);
            this->LrcList.append(lrc); //歌词列表
            QQmlContext* lrc_list = this->myView->rootContext();
            lrc_list->setContextProperty("myLRC",QVariant::fromValue(LrcList));
            int pos =rx.indexIn(str);
            if(pos > -1){
                QString time = rx.cap(0);
                QString t2 = time.mid(4,2) + time.mid(7,2);
                qint64 totime = (time.mid(1,2).toInt()*60) + t2.toInt()/100;
                this->timelist.push_back(totime);

            }
        }
    }
    else{
        int timee = time/1000;
        for(int i = 0; i < this->timelist.size(); i++){
            if(timelist[i] == timee && timee!=0){
                mysum = i*35;     //设置滚动距离
                positionChanged();
                QQmlContext* y = this->myView->rootContext();
                y->setContextProperty("LRC_Y",QVariant(mysum));//滚动
            }
        }

    }

    return this->LrcList;
}

void Music::clearLrc(){
    this->LrcList.clear();
    this->timelist.clear();
}

void Music::cleraLrcView(){
    clearLrc();
    QStringList* str = new QStringList;
    str->append("没找到歌词");
    QQmlContext* clear = this->myView->rootContext();
    clear->setContextProperty("myLRC",QVariant::fromValue(*str));
    delete str;
}

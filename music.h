#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include <io.h>
#include <fstream>
#include <iostream>
#include <QQmlContext>
#include <QFile>
#include <QVariant>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QMediaPlaylist>
#include <QTextCodec>
#include <QMediaMetaData>
#include <QTime>
using namespace std;

class Music: public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 nowtime READ times WRITE settime)
    Q_PROPERTY(qint64 endtime READ endTime WRITE setEndtime)

signals:
    Q_INVOKABLE void positionChanged();
    Q_INVOKABLE void clearlrcview();

public:
    Music(QObject *p = 0);
    ~Music();
    //vector<vector<QString>>* list; //vector<vector<QString>> list(1,vector<QString>(1));
    QString name;
    //Q_INVOKABLE void setview(QQuickView* view2);
    Q_INVOKABLE void startPlay(QString name);           //开始播放
    Q_INVOKABLE void setview(QQmlApplicationEngine *v); //设置歌词视图
    Q_INVOKABLE void ShowMusicList();                   //显示歌单
    Q_INVOKABLE void lastMusic();                       //上一首
    Q_INVOKABLE void nextMusic();                       //下一首
    Q_INVOKABLE void pausePlay();                       //暂停
    Q_INVOKABLE void setVol(int v= 80);                 //设置音量
    Q_INVOKABLE int getVol();                           //得到音量
    Q_INVOKABLE qint64 getEndtime();                    //设置歌曲结束时间
    Q_INVOKABLE QString getMusicTitle();                //获得歌曲名字
    Q_INVOKABLE QStringList showlrc(QString name,qint64 time);//显示歌词
    Q_INVOKABLE QVariant musicType();                         //音乐播放模式
    Q_INVOKABLE void setNowMusicPos(qint64 nowtime);          //调整音乐播放进度
    Q_INVOKABLE QQuickView *ViewMusicList();                  //歌单视图

    //以下用于QML显示
    qint64 times();                             //获得当前时间
    void settime(qint64 time_);                 //设置当前时间
    qint64 endTime();                           //获得结束时间
    void setEndtime(qint64 settime_);           //设置结束时间

private:
    QString timeformat(qint64 musictime);       //时间格式转换 ms->min:sec
    void clearLrc();                            //清除歌单
    void cleraLrcView();                        //清除歌词视图
    QStringList LrcList;                        //歌词表
    vector<int> timelist;                       //时间表
    QMediaPlayer* now;                          //当前播放指针
    QMediaPlaylist* playlist;                   //播放列表
    QQmlApplicationEngine* myView;              //qml的视图
    qint64 nowtime;                             //当前时间
    qint64 endtime;                             //结束时间
    int mysum;                                  //用于歌词视图的滚动
    int vol;                                    //音量默认80
    int tag;                                    //标记 用于查找歌曲/歌曲名
    bool k;                                     //用于暂停与继续播放的切换

};

#endif // MUSIC_H

#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include <io.h>
#include <fstream>
#include <iostream>
#include <QQmlContext>
//#include <QStringListModel>
//#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QQuickView>
//#include <QVariant>
#include <QTextCodec>
using namespace std;

class Music: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString name READ Name WRITE setName NOTIFY Cname)
signals:
    void play_pause();
    void cname();
public slots:
     void StartPlay(QString name);
     void LastMusic();
     void NextMusic();
     void PausePlay();
public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    QString list[1001];
    QString name;
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void VOL(int v= 80);  //调整声音
    Q_INVOKABLE bool MusicLoop(bool l=false); //是否循环播放 默认列表顺次循环
    Q_INVOKABLE QQuickView *ViewMusicList();

private:
    QMediaPlayer* now;
    int vol = 80;//音量 默认80
    int tag = 0; //标记为0代表第一个音乐文件
};

#endif // MUSIC_H

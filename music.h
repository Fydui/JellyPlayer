#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include <io.h>
#include <fstream>
#include <iostream>
#include <QQmlContext>
#include <QStringListModel>
#include <QQmlComponent>
using namespace std;

class Music: public QObject
{
    Q_OBJECT
    Q_PROPERTY(string list READ list WRITE setlist NOTIFY listChanged)
signals:
     //
public slots:
     void StartPlay(string name);
     void LastMusic();
     void NextMusic();
     void PausePlay();
     void ViewMusicList();
public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    Q_INVOKABLE string list[1001];
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void VOL(int v= 80);  //调整声音
    Q_INVOKABLE bool MusicLoop(bool l=false); //是否循环播放 默认列表顺次循环

private:
    QMediaPlayer* now;
    int vol = 80;//音量 默认80
    int tag = 0; //标记为0代表第一个音乐文件
};

#endif // MUSIC_H

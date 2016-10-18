#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include <io.h>
#include <fstream>
#include <iostream>
using namespace std;

class Music: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(string text READ text WRITE setText NOTIFY textChanged)

public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    Q_INVOKABLE string list[1000];
    Q_INVOKABLE void ShowMusicList(const char* path);
    Q_INVOKABLE void StartPlay(QString name);
    Q_INVOKABLE void PausePlay();
    Q_INVOKABLE void VOL(int v);  //调整声音
    /*Q_INVOKABLE void LastMusic(QMediaPlayer* name);
    Q_INVOKABLE void NextMusic(QMediaPlayer* name);
    Q_INVOKABLE void MusicLoop(QMediaPlayer* name,bool l); //是否循环播放 默认列表顺次循环
*/
private:
    QMediaPlayer* now;
    int vol = 80;

};

#endif // MUSIC_H

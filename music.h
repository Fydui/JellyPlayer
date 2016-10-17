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


signals:
    void start();


public:
    string list[1000];
    Music(QObject *p = 0);

    Q_INVOKABLE void ShowMusicList(const char* path);
    /*Q_INVOKABLE void StartPlay();
    Q_INVOKABLE void PausePlay();
    Q_INVOKABLE void LastMusic();
    Q_INVOKABLE void NextMusic();
    Q_INVOKABLE void VOL(int v);  //调整声音
    Q_INVOKABLE void MusicLoop(bool l); //是否循环播放 默认列表顺次循环
*/
public slots:



};

#endif // MUSIC_H

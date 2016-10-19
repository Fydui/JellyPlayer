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
    //Q_PROPERTY(string list READ list WRITE setlist NOTIFY listChanged)

public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    Q_INVOKABLE string list[1001];
    Q_INVOKABLE void ShowMusicList(string path);
    Q_INVOKABLE void StartPlay(string name);
    Q_INVOKABLE void PausePlay();
    Q_INVOKABLE void VOL(int v= 80);  //��������
    Q_INVOKABLE void LastMusic();
    Q_INVOKABLE void NextMusic();
    Q_INVOKABLE bool MusicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��

private:
    QMediaPlayer* now;
    int vol = 80;//���� Ĭ��80
    int tag = 0; //���Ϊ0�����һ�������ļ�
};

#endif // MUSIC_H

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
#include <QQmlApplicationEngine>

using namespace std;

class Music: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(string list READ list WRITE list)
//signals:
     //
public slots:
     void StartPlay(string name);
     void LastMusic();
     void NextMusic();
     void PausePlay();
     //void ViewMusicList();
public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    string list[1001];
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void VOL(int v= 80);  //��������
    Q_INVOKABLE bool MusicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��

private:
    QMediaPlayer* now;
    int vol = 80;//���� Ĭ��80
    int tag = 0; //���Ϊ0�����һ�������ļ�
};

#endif // MUSIC_H

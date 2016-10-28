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
#include <QVariant>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QMediaPlaylist>
#include <QTextCodec>
#include <QMediaMetaData>
using namespace std;

class Music: public QObject
{
    Q_OBJECT
signals:
    void play_pause();

public slots:
     //Q_INVOKABLE void StartPlay();


public:
    Music(QObject *p = 0);
    ~Music();
    //vector<vector<QString>>* list; //vector<vector<QString>> list(1,vector<QString>(1));
    QString name;
    Q_INVOKABLE void startPlay(QString name);
    Q_INVOKABLE void test(QString a);
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void lastMusic();
    Q_INVOKABLE void nextMusic();
    Q_INVOKABLE void pausePlay();
    Q_INVOKABLE void setVol(int v= 80);  //��������
    Q_INVOKABLE bool musicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��
    Q_INVOKABLE void setNowMusicPos(qint64 time);
    //Q_INVOKABLE void setPorgressLenght(qint64 time);
    Q_INVOKABLE QQuickView *ViewMusicList();

private:
    QMediaPlayer* now = NULL;
    QMediaPlaylist* playlist;
    qint64 time = 0;
    qint64 endtime = 0;
    int vol = 80;//���� Ĭ��80
    int tag = 0; //����Ϊ0������һ�������ļ�
    bool k = false;

};

#endif // MUSIC_H

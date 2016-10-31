#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include <io.h>
#include <fstream>
#include <iostream>
#include <QQmlContext>
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
    Q_PROPERTY(qint64 nowtime READ times WRITE settime)
    Q_PROPERTY(qint64 endtime READ endTime WRITE setEndtime)

signals:
    void play_pause();

public:
    Music(QObject *p = 0);
    ~Music();
    //vector<vector<QString>>* list; //vector<vector<QString>> list(1,vector<QString>(1));
    QString name;
    Q_INVOKABLE void startPlay(QString name);
    Q_INVOKABLE void test(QQuickView *v);
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void lastMusic();
    Q_INVOKABLE void nextMusic();
    Q_INVOKABLE void pausePlay();
    Q_INVOKABLE void setVol(int v= 80);  //��������
    Q_INVOKABLE bool musicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��
    Q_INVOKABLE void setNowMusicPos(qint64 nowtime);
    //Q_INVOKABLE void setPorgressLenght(qint64 time);
    Q_INVOKABLE QQuickView *ViewMusicList();

    qint64 times();
    void settime(qint64 time_);
    qint64 endTime();
    void setEndtime(qint64 settime_);

private:
    QString timeformat(qint64 musictime);
    QMediaPlayer* now = NULL;
    QMediaPlaylist* playlist;
    QQuickView* myView  = NULL;
    qint64 nowtime = 0;
    qint64 endtime = 0;
    int vol = 80;//���� Ĭ��80
    int tag = 0; //����Ϊ0������һ�������ļ�
    bool k = false;

};

#endif // MUSIC_H

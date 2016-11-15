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
//public slots:

public:
    Music(QObject *p = 0);
    ~Music();
    //vector<vector<QString>>* list; //vector<vector<QString>> list(1,vector<QString>(1));
    QString name;
    //Q_INVOKABLE void setview(QQuickView* view2);
    Q_INVOKABLE void startPlay(QString name);
    Q_INVOKABLE void setview(QQmlApplicationEngine *v);
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void lastMusic();
    Q_INVOKABLE void nextMusic();
    Q_INVOKABLE void pausePlay();
    Q_INVOKABLE void setVol(int v= 80);  //��������
    Q_INVOKABLE int getVol();
    Q_INVOKABLE qint64 getEndtime();
    Q_INVOKABLE QString getMusicTitle();
    Q_INVOKABLE QString getMusicTitle(QString name);
    Q_INVOKABLE bool musicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��
    Q_INVOKABLE void setNowMusicPos(qint64 nowtime);
    Q_INVOKABLE QQuickView *ViewMusicList();
    Q_INVOKABLE QStringList showlrc(QString name,qint64 time);



    qint64 times();
    void settime(qint64 time_);
    qint64 endTime();
    void setEndtime(qint64 settime_);

private:
    QString timeformat(qint64 musictime);
    void getMusicPix(QMediaPlayer *my);
    void clearLrc();
    void cleraLrcView();
    QStringList LrcList; //歌词表
    vector<int> timelist;

    QMediaPlayer* now = NULL;
    QMediaPlaylist* playlist;
    //QQuickView* myView  = NULL;
    QQmlApplicationEngine* myView  = NULL;
    qint64 nowtime = 0;
    qint64 endtime = 0;
    int mysum = 0;
    int vol = 80;//音量默认80
    int tag = 0;
    bool k = false;

};

#endif // MUSIC_H

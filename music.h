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
    void positionChanged(qint64);
public slots:
     //Q_INVOKABLE void StartPlay();
     void LastMusic();
     void NextMusic();
     void PausePlay();

public:
    Music(QObject *p = 0);
    ~Music(){delete now;}
    QString list[1001];
    QString name;
    Q_INVOKABLE void startPlay(QString name);
    Q_INVOKABLE void test(QString a);
    Q_INVOKABLE void ShowMusicList();
    Q_INVOKABLE void VOL(int v= 80);  //��������
    Q_INVOKABLE bool MusicLoop(bool l=false); //�Ƿ�ѭ������ Ĭ���б�˳��ѭ��
    Q_INVOKABLE QQuickView *ViewMusicList();

private:
    QMediaPlayer* now;
    int vol = 80;//���� Ĭ��80
    int tag = 0; //����Ϊ0������һ�������ļ�
};

#endif // MUSIC_H

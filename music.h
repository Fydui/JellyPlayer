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

public:
    Music(QObject *p = 0);
    ~Music();
    //vector<vector<QString>>* list; //vector<vector<QString>> list(1,vector<QString>(1));
    QString name;
    //Q_INVOKABLE void setview(QQuickView* view2);
    Q_INVOKABLE void startPlay(QString name);           //��ʼ����
    Q_INVOKABLE void setview(QQmlApplicationEngine *v); //���ø����ͼ
    Q_INVOKABLE void ShowMusicList();                   //��ʾ�赥
    Q_INVOKABLE void lastMusic();                       //��һ��
    Q_INVOKABLE void nextMusic();                       //��һ��
    Q_INVOKABLE void pausePlay();                       //��ͣ
    Q_INVOKABLE void setVol(int v= 80);                 //��������
    Q_INVOKABLE int getVol();                           //�õ�����
    Q_INVOKABLE qint64 getEndtime();                    //���ø�������ʱ��
    Q_INVOKABLE QString getMusicTitle();                //��ø�������
    Q_INVOKABLE QStringList showlrc(QString name,qint64 time);//��ʾ���
    Q_INVOKABLE QVariant musicType();                         //���ֲ���ģʽ
    Q_INVOKABLE void setNowMusicPos(qint64 nowtime);          //�������ֲ��Ž���
    Q_INVOKABLE QQuickView *ViewMusicList();                  //�赥��ͼ

    //��������QML��ʾ
    qint64 times();                             //��õ�ǰʱ��
    void settime(qint64 time_);                 //���õ�ǰʱ��
    qint64 endTime();                           //��ý���ʱ��
    void setEndtime(qint64 settime_);           //���ý���ʱ��

private:
    QString timeformat(qint64 musictime);       //ʱ���ʽת�� ms->min:sec
    void clearLrc();                            //����赥
    void cleraLrcView();                        //��������ͼ
    QStringList LrcList;                        //��ʱ�
    vector<int> timelist;                       //ʱ���
    QMediaPlayer* now;                          //��ǰ����ָ��
    QMediaPlaylist* playlist;                   //�����б�
    QQmlApplicationEngine* myView;              //qml����ͼ
    qint64 nowtime;                             //��ǰʱ��
    qint64 endtime;                             //����ʱ��
    int mysum;                                  //���ڸ����ͼ�Ĺ���
    int vol;                                    //����Ĭ��80
    int tag;                                    //��� ���ڲ��Ҹ���/������
    bool k;                                     //������ͣ��������ŵ��л�

};

#endif // MUSIC_H

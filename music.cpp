#include "music.h"
using namespace std;
Music::Music(QObject *p):
    QObject(p)
{
    //
}

void Music::ShowMusicList(const char* path)
{
    _finddata_t file;
     int k,i = 0;
     long HANDLE;
     k = HANDLE = _findfirst( path, &file );
     while( k != -1 ){
      this->list[i] = file.name;
      k = _findnext( HANDLE, &file );
      i++;
     }
     _findclose( HANDLE );
     return;
}

void Music::StartPlay(QString name)
{
    this->now = new QMediaPlayer;
    connect(this->now, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    this->now->setMedia(QUrl::fromLocalFile("music/"+name+".mp3"));
    this->now->setVolume(this->vol);
    this->now->play();
}

void Music::PausePlay()
{
    this->now->pause();
}

void Music::VOL(int v)
{
    this->now->setVolume(v);
}

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

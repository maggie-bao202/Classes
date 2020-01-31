#include "Media.h" //connect to parent
#include <iostream>

using namespace std;
//child class of Media class
class Music:public Media {
 public:
  Music(char* newTitle, char* artist, int year, float duration, char* publisher); //methods and variables unique to Music class
  virtual void printMedia();
  char* getArtist();
  float getDuration();
  char* getPublisher();
  ~Music();
 private:
  char* artist;
  float duration;
  char* publisher;
};

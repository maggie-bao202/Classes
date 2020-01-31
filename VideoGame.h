#include "Media.h"
#include <iostream>

using namespace std;
//initialize variables and functions unique to VideoGame
class VideoGame:public Media {
 public:
  VideoGame(char* newTitle, int year, char* publisher, float rating);
  void printMedia();
  char* getPublisher();
  float getRating();
  ~VideoGame();
private: //variables best to be private, not tamperable outside
  char* publisher;
  float rating;
};

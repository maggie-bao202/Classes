#include "Media.h"
#include <iostream>
//intialize all variables and add function prototypes unique to Movie
using namespace std;

class Movie:public Media {
 public:
  Movie(char* newTitle, char* director, int year, float duration, float rating);
  void printMedia();
  char* getDirector();
  float getDuration();
  float getRating();
  ~Movie();
 private:
  char* director;
  float duration;
  float rating;
};
    

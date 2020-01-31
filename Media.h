#include <iostream>

#ifndef MEDIA_H//header guard, if media is not defined, then define
#define MEDIA_H

using namespace std;
//.h files where all the function prototypes go
class Media {//variables all children have in common
protected://variables can not be public
  int type;
  int year;
  char* title;
public: //functions
  Media(char* title, int year);
  virtual ~Media(); //virtual: take information of children to overwrite parent
  virtual void printMedia();
  
  char* getTitle();
  int getYear();
  int getType();
};
#endif

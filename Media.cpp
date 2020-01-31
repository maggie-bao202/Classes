#include <iostream>
#include "Media.h"

using namespace std;
//parent class "Media"
Media::Media(char* newTitle, int newYear) {//constructor
  title = newTitle;
  year = newYear;
}
void Media::printMedia() {
  cout << endl;
}

Media::~Media() { //destructor
}

//getters
char* Media::getTitle() {
  return title;
}
int Media::getYear() {
  return year;
}
int Media::getType() {
  return type;
}

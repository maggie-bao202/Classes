#include "Music.h"
#include <iostream>

using namespace std;
//Functions unique to Music
Music::Music(char* newTitle, char* newArtist, int newYear, float newDuration, char* newPublisher) : Media(newTitle, newYear){ //contructor
  type = 2;
  title = newTitle;
  artist = newArtist;
  year = newYear;
  duration = newDuration;
  publisher = newPublisher;
}
void Music::printMedia(){
  cout << "Music" << endl;
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  cout << "Year: " << year << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
}
char* Music::getArtist(){
  return artist;
}
float Music::getDuration(){
  return duration;
}

char* Music::getPublisher(){
  return publisher;
}

Music::~Music(){ //destructor, have to delete memory of char*
  delete[] title;
  delete[] artist;
  delete[] publisher;
}

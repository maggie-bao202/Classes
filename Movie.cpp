#include "Movie.h"
#include <iostream>

using namespace std;
//Movie is a child of Media
Movie::Movie(char* newTitle, char* newDirector, int newYear, float newDuration, float newRating) : Media(newTitle, newYear){//Constructor
  type = 0;
  title = newTitle;
  director = newDirector;
  year = newYear;
  duration = newDuration;
  rating = newRating;
}
void Movie::printMedia(){
  cout << "Movie" << endl;
  cout << "Title: " << title << endl;
  cout << "Director: " << director << endl;
  cout << "Year: " << year << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
}

char* Movie::getDirector(){
  return director;
}
float Movie::getDuration(){
  return duration;
}
float Movie::getRating(){
  return rating;
}

Movie::~Movie(){ //destructor
  delete[] title;
  delete[] director;
}

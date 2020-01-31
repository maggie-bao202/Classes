#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"
#include <iomanip>
#include <iterator>

using namespace std;

/*Date: 11/12/19 Author: Maggie Bao Description: Classes prompts the user to input a keyword "ADD", "SEARCH", "DELETE", or "QUIT". If the input is "ADD", they have to select the type of media -- a movie, song, or video game-- then enter in the description following the media chosen. When the user types in "SEARCH", the program will ask the user if they want to search by media title or by year, then the user will have to specify the media accordingly. The program will then display all media under the same title/year. When the user types in "DELETE", the program will ask for either a title or a year input, then confirm if the media they want to delete is correct. By "QUIT", the program will end. */


//function prototypes:
void addMedia(vector<Media*>*);
void searchMedia(vector<Media*>*);
void deleteMedia(vector<Media*>*);

int main(){
  vector<Media*>* mediaList = new vector<Media*>(); //create a vector pointer of media pointers
  char keyword[40];
  bool stillPlaying = true;
  while (stillPlaying == true){
    cout << "Type in a keyword (\"ADD\", \"SEARCH\",\"DELETE\", or \"QUIT\"):"<<endl;
    cin >> keyword; //put input into char array keyword
    cin.ignore();
    if (strcmp(keyword, "ADD") == 0){//if the input is ADD
      cout << endl; //formatting
      addMedia(mediaList); //addMedia function that reads vector pointer
      cout << endl;
    }
    else if (strcmp(keyword, "SEARCH") == 0){//Similar to above
      cout << endl;
      searchMedia(mediaList);
      cout << endl;
    }
    else if (strcmp(keyword, "DELETE") == 0){
      cout << endl;
      deleteMedia(mediaList);
      cout << endl;
    }
    else if (strcmp(keyword, "QUIT") == 0){//if quit, boolean is false so program will stop
      cout << "Have a nice day!" << endl;
      stillPlaying = false;
    }
    else{//if not a valid keyword
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  return 0;
}
	      
void addMedia(vector<Media*>* mediaList){//user inputs information into media
  int type;
  cout << "Type in \"0\" to add a movie, \"1\" to add a video game, and \"2\" to add a song." << endl;
  cin >> type;
  cin.ignore();
  cout << "Enter in the following information for a ";
  if (type == 0){//if movie
    char* title = new char(40);
    char* director = new char(40);
    int year = 0;
    float duration = 0;
    float rating = 0;
    
    //from input, store in variables with type corresponding to class Movie
    cout << "movie:" << endl;
    cout << "Title: ";
    cin.getline(title, 40, '\n');
    cout << "Director: ";
    cin.getline(director, 40, '\n');
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    cout << "Duration: ";
    cin >> duration;
    cin.ignore();
    cout << "Rating: ";
    cin >> rating;
    cin.ignore();
    Movie *media = new Movie(title, director, year, duration, rating); //put into pointer media, under a Movie pointer. Same order as in constructor
    mediaList->push_back(media);//add to vector pointer mediaList
    cout << "Movie Added." << endl;
  }
  if (type == 1){//user inputs information into video game
    char* title = new char(40);
    char* publisher = new char(40);
    int year = 0;
    float rating = 0;

    //from input, establish variable types to put into VideoGame class
    cout << "video game:" << endl;
    cout << "Title: ";
    cin.getline(title, 40, '\n');
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    cout << "Publisher: ";
    cin.getline(publisher, 40, '\n');
    cout << "Rating: ";
    cin >> rating;
    cin.ignore();
    VideoGame* media = new VideoGame(title, year, publisher, rating);//puts into Media pointer under Movie
    mediaList->push_back(media);//add to vector
    cout << "Video Game Added." << endl;
  }
  if (type == 2){//user inputs information into music
    char* title = new char[40];
    char* artist = new char[40];
    char* publisher = new char[40];
    int year = 0;
    float duration = 0;
    
    cout << "song:" << endl;
    cout << "Title: ";
    cin.getline(title, 40, '\n');
    cout << "Artist: ";
    cin.getline(artist, 40, '\n');
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    cout << "Duration: ";
    cin >> duration;
    cin.ignore();
    cout << "Publisher: ";
    cin.getline(publisher, 40, '\n');
    Music* media = new Music(title, artist, year, duration, publisher);
    mediaList->push_back(media);
    cout << "Song Added." << endl;
  }
}
	      
void searchMedia(vector<Media*>* mediaList){//displays the media the user had inputted
vector<Media*>::iterator it; //create iterator
  int input = 0;
  cout << "Enter \"0\" to search by title, and \"1\" to search by year." << endl;
  cin >> input;//take 0 for title, 1 for year
  cin.ignore();
  if (input == 0){//if user wants to search by title
    cout << "Enter the media title: ";
    char* ititle = new char(40);
    cin.getline(ititle, 40, '\n');//enter title
    for(it = mediaList->begin(); it != mediaList->end(); it++){// goes through each element of the vector using the iterator
      if (strcmp((*it)->getTitle(), ititle) == 0){//if the title matches up with any media title
	cout << endl;
	(*it)->printMedia();//print media, in whichever format specified in the type.cpp file
      }
    }
  }
  if (input == 1){//if search by year
    cout << "Enter the media year: ";
    int iyear = 0;
    cin >> iyear;
    cin.ignore();
    for(it = mediaList->begin(); it != mediaList->end(); it++){// goes through each element of the vector
      if ((*it)->getYear() == iyear){ // it year matches up with any media's year. for pointers, use ->
	cout << endl;
	(*it)->printMedia();//print the following media(s)
      }
    }
  }
}

void deleteMedia(vector<Media*>* mediaList) {
vector<Media*>::iterator it; //create iterator
  int input = 0;
  cout << "Enter \"0\" to delete by title, and \"1\" to delete by year." << endl;
  cin >> input;
  cin.ignore();
  if (input == 0){//if delete using title
    cout << "Enter the media title: ";
    char* ititle = new char(40);
    cin.getline(ititle, 40, '\n');
    for(it = mediaList->begin(); it != mediaList->end(); it++){// goes through each element of the vector
      if (strcmp((*it)->getTitle(), ititle) == 0){//if element's title matches up
	cout << "Are you sure you want to delete: " << (*it)->getTitle() << "? (Y/N)" << endl;//confimation
	cout << endl;
	(*it)->printMedia();//show the media user wants to delete
	cout << endl;
	char response = ' ';
	cin >> response;
	cin.ignore();
	if (response == 'Y' || response == 'y') {//if they want to delete
	  delete *it;//delete memory
	  mediaList->erase(it);//remove from iterator
	  cout << "Media Deleted." << endl;
	  return; //go back to main
	}
      }
    }
  }
  if (input == 1){//if delete using year
    cout << "Enter the media year: ";
    int iyear = 0;
    cin >> iyear;
    cin.ignore();
    for(it = mediaList->begin(); it != mediaList->end(); it++){// goes through each element of the vector
      if ((*it)->getYear() == iyear){//if year matches up
        cout << "Are you sure you want to delete: " << (*it)->getTitle() << "? (Y/N)" << endl;//confirmation
	cout << endl;
	(*it)->printMedia();//show media user wants to delete
	cout << endl;
        char response = ' ';
        cin >> response;
        cin.ignore();
        if (response == 'Y' || response == 'y') {//manually calls destructor
          delete *it;//delete memory
          mediaList->erase(it);//remove from iterator
	  cout << "Media Deleted." << endl;
	  return;//go back to main
	}
      }
    }
  }
}

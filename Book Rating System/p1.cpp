// Tyler Baker
// p1.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Book.h"
#include "Member.h"
#include "Rating.h"
using namespace std;

// MM stands for main menu
const int MM_ADD_MEMBER = 1;
const int MM_ADD_BOOK = 2;
const int MM_LOGIN = 3;
const int MM_QUIT = 4;

// UM stands for user menu
const int UM_VIEW_RATINGS = 1;
const int UM_RATE = 2;
const int UM_SEE_REC = 3;
const int UM_LOGOUT = 4;
const int UM_QUIT = 5;


void loadData(Book &books, int &isbn, Rating &ratings, Member &members);
int mainMenu();
int userMenu(string loggedInUser);

void doAddBook(Book &books);
void doAddMember(Member &members);

int main()
{
  Book books;
  Member members;
  Rating ratings;
  
  int isbn = 1;
  int mmSelection = 0;
  int umSelection = 0;
  int loginUserIndex;
  
  bool login = false;
  string tempUsername;
  string loginUser;

  srand(time(0));
  
  loadData(books, isbn, ratings, members);
  
  
  

  while(!login){
	cout << endl << endl;
	mmSelection = 0;
	mmSelection = mainMenu();
	
	switch(mmSelection){
	  
	case MM_ADD_MEMBER:
	  doAddMember(members);
	  break;
	  
	case MM_ADD_BOOK:
	  doAddBook(books);
	  break;
	  
	case MM_LOGIN:
	  cout << "Please enter your username: ";
	  cin >> tempUsername;
	  login = members.login(tempUsername, loginUserIndex);
	  loginUser = tempUsername;
	  break;
	  
	case MM_QUIT:
	  return 0;
	  
	}

	
	while(login){
	  cout << endl << endl;
	  umSelection = 0;
	  umSelection = userMenu(loginUser);
	  
	  switch(umSelection){
		
	  case UM_VIEW_RATINGS:
		ratings.viewRatings(loginUserIndex, books);
		break;
		
	  case UM_RATE:
		ratings.rateBookFromInput(books, loginUserIndex);
		break;
		
	  case UM_SEE_REC:
		ratings.viewRecommended(books, loginUserIndex);
		break;

	  case UM_LOGOUT:
		login = false;
		loginUser = "";
		break;
	  case UM_QUIT:
		return 0;
		
	  }
	  
	}
  }
  
  return 0;
}


void loadData(Book &books, int &isbn, Rating &ratings, Member &members)
{
  
  ifstream fileHandle;
  
  string fileName1 = "books.txt";
  string fileName2 = "ratings.txt";
  int memberIndex;
  int tempRating;
  int ratingIndex = 0;
  string tempAuthor;
  string tempTitle;
  string tempName;
  string tempUsername;
  string tempString;
  string line;
  
  fileHandle.open(fileName1);
  
  while(getline(fileHandle,tempAuthor,',')){

	
	getline(fileHandle,tempTitle);
	
	books.addBook(isbn,tempTitle,2015,tempAuthor);
	isbn++;
  }
  
  
  fileHandle.close();
  
  
  fileHandle.open(fileName2);
  while(getline(fileHandle,tempName)){
	tempUsername = tempName;
	memberIndex = members.addMember(tempName, tempUsername);
	
	ratingIndex = 0;
	
	getline(fileHandle, line);
	
	stringstream ssin(line);
	while(ssin >> tempString){
	  tempRating = stoi(tempString);
	  ratings.rateBook(memberIndex, ratingIndex, tempRating);
	  ratingIndex++;
	  
	}
  }
  fileHandle.close();
  
}

int mainMenu()
{
  int userSelection = -1;

  cout << "MAIN MENU" << endl;
  cout << "---------" << endl << endl;
  while(userSelection < MM_ADD_MEMBER || userSelection > MM_QUIT){
	cout << MM_ADD_MEMBER << ". Add Member" << endl;
	cout << MM_ADD_BOOK << ". Add Book" << endl;
	cout << MM_LOGIN << ". Login" << endl;
	cout << MM_QUIT << ". Quit" << endl;

	cout << "Selection: ";
	cin >> userSelection;
  }

  return userSelection;
}

int userMenu(string loggedInUser)
{
  int userSelection = -1;

  cout << "USER MENU" << endl;
  cout << "---------" << endl << endl;
  cout << loggedInUser << " is logged in" << endl << endl;
  while(userSelection < UM_VIEW_RATINGS || userSelection > UM_QUIT){
	cout << UM_VIEW_RATINGS << ". View Ratings" << endl;
	cout << UM_RATE << ". Rate Book" << endl;
	cout << UM_SEE_REC << ". See Recommendations" << endl;
	cout << UM_LOGOUT << ". Logout" << endl;
	cout << UM_QUIT << ". Quit" << endl;

	cout << "Selection: ";
	cin >> userSelection;
  }

  return userSelection;
}

void doAddBook(Book &books)
{
  int isbnIn, yearIn;
  string titleIn, authorIn;

  

  cout << "Would you like to add book?" << endl << endl; // FINISH THIS

  cout << "Please enter the book's ISBN: ";
  cin >> isbnIn;

  cin.ignore();
  cout << "Please enter the book's title: ";
  getline(cin, titleIn);

  cout << "Please enter the book's author: ";
  getline(cin, authorIn);

  cout << "Please enter the book's year: ";
  cin >> yearIn;

  books.addBook(isbnIn, titleIn, yearIn, authorIn);

}

void doAddMember(Member &members)
{
  string name, username;

  cout << "Would you like to add a user?" << endl << endl; // FINISH THIS

  cin.ignore();
  cout << "Please enter the user's name: ";
  getline(cin, name);

  
  cout << "Please enter the desired username: ";
  cin >> username;

  members.addMember(name, username);
}

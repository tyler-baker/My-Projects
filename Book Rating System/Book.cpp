// Tyler Baker
// 4.21.15
// Book.cpp 1.0


#include "Book.h"
#include <iostream>
using namespace std;



/* CONSTRUCTOR */
Book::Book()
{
  books = new BookData[arraySize];
}

Book::~Book()
{
  delete [] books;
}

Book::Book(const Book &rhs)
{
  numBooks = rhs.numBooks;
  arraySize = rhs.arraySize;

  for(int i = 0; i < numBooks; i++)
	books[i] = rhs.books[i];

}

Book &Book::operator=(const Book &rhs)
{
  if(this != &rhs){
	numBooks = rhs.numBooks;
	arraySize = rhs.arraySize;
	
	for(int i = 0; i < numBooks; i++)
	  books[i] = rhs.books[i];
  }
  
  return *this;
}

/* Member Functions */
int Book::getNumBooks() const
{
  return numBooks;
}

bool Book::addBook(int isbnIn, string titleIn, int yearIn, string authorIn)
{
  char badIsbnCatch;
  bool isbnGood = false;

  while(!isbnGood){
	isbnGood = true;
	for(int i = 0; i < numBooks; i++){
	  
	  if(books[i].isbn == isbnIn && (isbnGood)){
		isbnGood = false;
		cout << "The ISBN (" << isbnIn << ") is already in the database" << endl;
		cout << "Would you like to change the ISBN (i) or cancel (c)? (i/c): ";
		cin >> badIsbnCatch;
		if(badIsbnCatch == CHANGE){
		  cout << endl << "Please enter a new ISBN: ";
		  cin >> isbnIn;
		}
		else
		  return false;
	  }
	}
  }
  if(numBooks == arraySize){
	int newSize = arraySize * 1.5;

	BookData *newArr = new BookData[newSize];
		
	  
	for(int i = 0; i < arraySize; i++)
	  newArr[i] = books[i];
	

	arraySize = newSize;
	
	delete [] books;
	books = newArr;
	numBooks++;
  }
  

  books[numBooks].isbn = isbnIn;
  books[numBooks].title = titleIn;
  books[numBooks].year = yearIn;
  books[numBooks].author = authorIn;

  numBooks++;

  
  return true;
  
}

int Book::getIsbn(int index) const
{
  return books[index].isbn;
}

string Book::getTitle(int index) const
{
  return books[index].title;
}

int Book::getYear(int index) const
{
  return books[index].year;
}

string Book::getAuthor(int index) const
{
  return books[index].author;
}

void Book::displayBook(int index) const
{
  
  cout << books[index].isbn << " | ";
  cout << "[" << books[index].title << "] | ";
  cout << "AUTHOR: " << books[index].author << " | ";
  

}
 



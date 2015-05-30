// Tyler Baker
// 4.21.15
// Book.h 1.0

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book
{
 public:
  Book();
  ~Book();
  Book(const Book &rhs);
  Book& operator=(const Book &rhs);

  bool addBook(int isbnIn, string titleIn, int yearIn, string authorIn);

  int getIsbn(int index);
  string getTitle(int index);
  int getYear(int index);
  string getAuthor(int index);
  int getNumBooks();
  void display(int index);
  
 private:
  struct BookData{
	int isbn;
	string title;
	int year;
	string author;
  };

  BookData *books;

  int numBooks = 0;
  int arraySize = 100;
  const char CANCEL = 'c';
  const char CHANGE = 'i';

};

#endif

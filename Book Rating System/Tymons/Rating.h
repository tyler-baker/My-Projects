#include <iostream>
#include <cassert>
#include "Book.h"
#include "Member.h"

#ifndef RATING_H
#define RATING_H

using namespace std;

class Rating
{
 public:

  Rating();
  // default constructor

  Rating(const Rating& r);
  // copy constructor

  Rating& operator=(const Rating& rhs);
  // overloaded assignment

  ~Rating();
  // destructor

  void rateFromFile(int rating, int row, int col);
  // puts rating in from file

  void viewRatings(const string accName, Book list, int member);
  // shows users ratings for all bokos

  void rateBook(const Book& list, int member);
  // puts rating for book

  void getTopFive(Book list, int member, int Rmember);
  // prints top 5 books

  void viewRecommended(const Book& bList, int member);
  // shows top 5 recommended

 private:

  int rows = 100;
  int cols = 100;

  int **rate;

};

#endif

// Tyler Baker
// 4.21.15
// Rating.h 1.0

#ifndef RATING_H
#define RATING_H

#include <iostream>
#include "Book.h"
using namespace std;

class Rating{

 public:
  Rating();
  ~Rating();
  Rating(const Rating &rhs);
  Rating& operator=(const Rating &rhs);

  void viewRatings(int userIndex, const Book &books);
  void viewRecommended(Book& books, int userIndex);
  void rateBook(int row, int col, int ratingValue);
  void rateBookFromInput(const Book &books, int userIndex);
  
 private:
  int **ratings;
  
  int cols = 100;
  int rows = 100;




};

#endif

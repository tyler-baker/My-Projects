// Tyler Baker
// 4.21.15
// Rating.cpp 1.0

#include "Rating.h"
#include "Book.h"
#include <iostream>
using namespace std;

Rating::Rating()
{
  ratings = new int*[cols];

  for(int i = 0; i < cols; i++)
	ratings[i] = new int[rows];
}

Rating::~Rating()
{
  for(int i = 0; i < cols; i++)
	delete [] ratings[i];
  delete [] ratings;
}

Rating::Rating(const Rating &rhs) 
{

}

Rating& Rating::operator=(const Rating &rhs)
{

  return *this;
}

void Rating::viewRatings(int userIndex, Book books)
{
  //for(int i = 0; i < books.getNumBooks(); i++){
  //books.display(i);
  //cout << userIndex;
  //cout << " | rating:" << ratings[userIndex][i] << endl;

  //}

}

void Rating::viewRecomended() 
{

}

void Rating::rateBook(int row, int col, int ratingVal)
{
  ratings[row][col] = ratingVal;
  cout << "ratings[" << row << "][" << col << "] = " << ratings[row][col] << endl;

}
  

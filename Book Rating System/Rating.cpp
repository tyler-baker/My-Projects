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
  Rating temp;

  for(int i = 0; i < rows; i++)
	for(int j = 0; j < cols; j++)
	  temp.ratings[i][j] = rhs.ratings[i][j];
}

Rating& Rating::operator=(const Rating &rhs)
{
  if(this != &rhs) {
	for(int i = 0; i < cols; i++)
	  delete [] ratings[i];
	
	for(int i = 0; i < rows; i++) {
	  for(int j = 0; j < cols; j++) {
		ratings[j][i] = rhs.ratings[j][i];
	  }
	}
  }
  
  return *this;
}

void Rating::viewRatings(int userIndex, const Book &books)
{
  int numBooks = books.getNumBooks();
  
  for(int i = 0; i < numBooks; i++){
	books.displayBook(i);
	cout << "rating:" << ratings[userIndex][i] << endl;
	
  }
}

void Rating::viewRecommended(Book& books, int userIndex) 
{
  int value,endValue;
  
  int index;
  int numBooks = books.getNumBooks();
  int similarReader[5] = {-1};
  int similarReaderCounter = 0;
  
  for(int i = 0; i < cols; i++){
	if(i == userIndex)
	  i++;
	for(int n = 0; n < rows; n++)
	  value += (ratings[userIndex][n] * ratings[n][i]);
	if(value > endValue){
	  endValue = value;
	  index = i;
	}

	
	for(int i = 0; i < numBooks; i++){
	  if(ratings[index][i] == 5 && ratings[userIndex][i] == 0){
		similarReader[similarReaderCounter] = i;
		similarReaderCounter++;
	  }
	}
	if(!similarReader[4] > -1){
	  for(int i = 0; i < numBooks; i++){
		if(ratings[index][i] == 4 && ratings[userIndex][i] == 0){
		  similarReader[similarReaderCounter] = i;
		  similarReaderCounter++;
		}
	  }
	  for(int i = 0; i < numBooks; i++){
		if(ratings[index][i] == 3 && ratings[userIndex][i] == 0){
		  similarReader[similarReaderCounter] = i;
		  similarReaderCounter++;
		}
	  }
	  for(int i = 0; i < numBooks; i++){
		if(ratings[index][i] == 2 && ratings[userIndex][i] == 0){
		  similarReader[similarReaderCounter] = i;
		  similarReaderCounter++;
		}
	  }
	  for(int i = 0; i < numBooks; i++){
		if(ratings[index][i] == 1 && ratings[userIndex][i] == 0){
		  similarReader[similarReaderCounter] = i;
		  similarReaderCounter++;
		}
	  }
	}
  }
  for(int i = 0; i < 5; i++){
	books.displayBook(similarReader[i]);
  }
}
  
void Rating::rateBook(int row, int col, int ratingVal)
{
  ratings[row][col] = ratingVal;


}

void Rating::rateBookFromInput(const Book &books, int userIndex)
{
  int rating,isbn;

  int numBooks = books.getNumBooks();
  
  for(int i = 0; i < numBooks; i++){
	books.displayBook(i);
	cout << endl;
  }
  cout << "Please enter the ISBN of the book you wish to rate: ";
  cin >> isbn;
  
  cout << "What is your rating for this book?: ";
  cin >> rating;
  ratings[userIndex][isbn]=rating;

}
  

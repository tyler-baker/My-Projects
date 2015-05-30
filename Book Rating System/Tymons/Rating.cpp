// Tymon Schroeder

// Rating.cpp

// implementation fo Rating.h

#include <iostream>
#include <cassert>
#include "Book.h"
#include "Rating.h"
#include "Member.h"

using namespace std;

Rating::Rating()
{
  rate = new int*[cols];
  assert(rate != nullptr);
  for(int i = 0; i < cols; i++) {
	rate[i] = new int[rows];
	assert(rate[i] != nullptr);
  }
}

Rating::Rating(const Rating& r)
{
  Rating obj;

  for(int i = 0; i < rows; i++)
	for(int j = 0; j < cols; j++)
	  obj.rate[i][j] = r.rate[i][j];
}

Rating& Rating::operator=(const Rating& rhs)
{
  if(this != &rhs) {
	for(int i = 0; i < cols; i++)
	  delete [] rate[i];

	for(int i = 0; i < rows; i++) {
	  for(int j = 0; j < cols; j++) {
		rate[j][i] = rhs.rate[j][i];
	  }
	}
  }

  return *this;
}

Rating::~Rating()
{
  for(int i = 0; i < cols; i++)
	delete [] rate[i];

  delete [] rate;
}

void Rating::rateFromFile(int rating, int row, int col)
{
  rate[row][col] = rating;

}

void Rating::viewRatings(const string accName, Book list, int member)
{
  cout << endl << "Ratings for " << accName << ":" << endl;
  
  for(int i = 0; i < list.getNumBooks(); i++) {

	list.displayBook(i);
	cout << rate[i][member];
  }

}

void Rating::rateBook(const Book& list, int member)
{
  int book;
  int rating;

  if(member > cols || list.getNumBooks() > rows) {
	int nCols = cols + (cols/2);
	int nRows = rows + (rows/2);
	int** temp = new int*[nCols];
	if(temp == nullptr)
	  return;
	for(int v = 0; v < nCols; v++) {
	  temp[v] = new int[nRows];
	  if(temp[v] == nullptr)
		return;
	}

	for(int i = 0; i < rows; i++) {
	  for(int j = 0; j < cols; j++) {
		temp[i][j] = rate[i][j];
	  }
	}
	for(int k = 0; k < cols; k++)
	  delete [] rate[k];
	delete [] rate;

	rate = temp;
	cols = nCols;
	rows = nRows;
  }
  
  cout << endl << "Press enter to rate a book:";
  cin.get();

  viewRatings("you", list, member);

  cout << endl << endl << "Give the ISBN of the book you with to rate: ";
  cin >> book;

  cout << "What rating do you give this book?";
  cout << endl << "-5   -3,   0   1   3   5" << endl << "Rating? ";
  cin >> rating;

  rate[book-1][member] = rating;

}

void Rating::getTopFive(Book list, int member, int Rmember)
{
  int* top = new int[list.getNumBooks()];
  int index = 0;
  
  for(int i = 0; i < list.getNumBooks(); i++) {
	if(rate[i][member] == 5 && rate[i][Rmember] == 0) {
	  top[index] = i;
	  index++;
	}
  }
  if(!top[5] > 0) {
	for(int i = 0; i < list.getNumBooks(); i++) {
	  if(rate[i][member] == 3 && rate[i][Rmember] == 0) {
		top[index] = i;
		index++;
	  }
	}
	if(!top[5] > 0) {
	  for(int i = 0; i < list.getNumBooks(); i++) {
		if(rate[i][member] == 1 && rate[i][Rmember] == 0) {
		  top[index] = i;
		  index++;
		}
	  }
	  for(int i = 0; i < list.getNumBooks(); i++) {
		if(rate[i][member] == 0 && rate[i][Rmember] == 0) {
		  top[index] = i;
		  index++;
		}
	  }
	}
  }

  for(int i = 0; i < 5; i++)
	list.displayBook(top[i]);

  delete [] top;
}

void Rating::viewRecommended(const Book& bList, int member)
{
  int num;
  int final = 0;
  int index;

  for(int i = 0; i < cols; i++) {
	if(i == member)
	  i++;
	for(int j = 0; j < rows; j++) {
	  num += (rate[j][member] * rate[j][i]);
	}
	if(num > final) {
	  final = num;
	  index = i;
	}
  }

  getTopFive(bList, index, member);
}


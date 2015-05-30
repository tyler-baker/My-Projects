// Tyler Baker
// 4.21.15
// DynArray.h 1.0

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "Book.h"
#include<iostream>
using namespace std;

class DynArrays
{

 public:
  DynArrays();
  bool addElement();

  bool resize();
 private:
  Book *bookArray;
  int bookCount;

  int elementCount;
  int currentArraySize;


};



#endif

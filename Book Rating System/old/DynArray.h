// Tyler Baker
// 4.21.15
// DynArray.h 1.0

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "Book.h"
#include<iostream>
using namespace std;

class DynArray
{

 public:
  DynArray();
  bool addElement();
  
  bool resize();
 private:
  int elementCount;
  int currentArraySize;
  Book books[20];
  
};



#endif

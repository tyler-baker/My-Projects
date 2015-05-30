// Tyler Baker
// Heap.h
// References: http://www.algolist.net/Data_structures/Binary_heap 

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
template <class T>

class Heap {
  private:
   vector<T> theHeap;
   bool isMinHeap;
   void percolateUp(int pos);
   void percolateDown(int pos, int heapSize);
   int left(int index);
   int right(int index);
	 int parent(int index);

  public:
    Heap();   //constructor
    Heap(bool isMinHeapIn);
    ~Heap();
    bool empty();  // return true if empty, otherwise false
    void insert(const T& item);  //insert an item into the heap
    T& getRoot();
    void removeRoot(); //remove the root (max/min) element from the heap
    void print();
    void heapSort();

};

// Private Functions

template <class T>
void Heap<T>::percolateUp(int pos)
{
	if(isMinHeap){
    while ( ( pos > 0 ) && ( parent(pos) >= 0 ) &&
            ( theHeap[parent(pos)] > theHeap[pos] ) )
    {
        T tmp = theHeap[parent(pos)];
        theHeap[parent(pos)] = theHeap[pos];
        theHeap[pos] = tmp;
        pos = parent(pos);
    }
	}else{
		while( ( pos > 0 ) && ( parent(pos) >= 0 ) && 
					 ( theHeap[parent(pos)] < theHeap[pos] ) )
					 {
			T tmp = theHeap[parent(pos)];
			theHeap[parent(pos)] = theHeap[pos];
			theHeap[pos] = tmp;
			pos = parent(pos);
		}
	}
}

template <class T>
void Heap<T>::percolateDown(int pos, int heapSize)
{
		int leftChildIndex, rightChildIndex, minIndex;
		T tmp;
		leftChildIndex = left(pos);
		rightChildIndex = right(pos);
		
		if(rightChildIndex >= heapSize){
			if(leftChildIndex >= heapSize)
				return;
			else
				minIndex = leftChildIndex;
		}else{
			if(isMinHeap){
				if(theHeap[leftChildIndex] < theHeap[rightChildIndex])
					minIndex = leftChildIndex;
				else
					minIndex = rightChildIndex;
			}else{
				if(theHeap[leftChildIndex] > theHeap[rightChildIndex])
					minIndex = leftChildIndex;
				else
					minIndex = rightChildIndex;
			}
		}
		if(isMinHeap){
			if(theHeap[pos] > theHeap[minIndex]){			
				tmp = theHeap[minIndex];
				theHeap[minIndex] = theHeap[pos];
				theHeap[pos] = tmp;
				percolateDown(minIndex, heapSize);
			}
		}else{
			if(theHeap[pos] < theHeap[minIndex]){	
				tmp = theHeap[minIndex];
				theHeap[minIndex] = theHeap[pos];
				theHeap[pos] = tmp;
				percolateDown(minIndex, heapSize);
			}
		}
}

template <class T>
int Heap<T>::left(int index)
{
  return index*2+1;
}

template <class T>
int Heap<T>::right(int index)
{
  return index*2+2;
}

// Public Functions

template <class T>
Heap<T>::Heap()
{
  isMinHeap = true;
}

template <class T>
Heap<T>::Heap(bool isMinHeapIn)
{
	isMinHeap = isMinHeapIn;
}

template <class T>
Heap<T>::~Heap()
{
}


template <class T>
void Heap<T>::insert(const T& item)
{
  theHeap.push_back(item);
  percolateUp(theHeap.size() -1);
}

template <class T>
int Heap<T>::parent(int index)
{
	return floor((index-1)/2);
}

template <class T>
void Heap<T>::print()
{
	for(int i = 0; i < theHeap.size(); i++)
		cout << theHeap[i];
}

template <class T>
bool Heap<T>::empty()
{
	return theHeap.empty();
}

template <class T>
T& Heap<T>::getRoot()
{
	return theHeap[0];
}

template <class T>
void Heap<T>::heapSort()
{
	T tmp;
	
	for(int i = theHeap.size() - 1; i > 0; i--){
		tmp = theHeap[i];
		theHeap[i] = theHeap[0];
		theHeap[0] = tmp;
		percolateDown(0, i);
	}

	for(int i = 0; i < theHeap.size()/2; i++){
		tmp = theHeap[theHeap.size() - i - 1];
		theHeap[theHeap.size() - i - 1] = theHeap[i];
		theHeap[i] = tmp;
	}
}

template <class T>
void Heap<T>::removeRoot()
{
	if(!empty())
		theHeap[0] = theHeap[theHeap.size()-1];
		theHeap.pop_back();
		percolateDown(0, theHeap.size());
}

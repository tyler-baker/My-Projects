// Tyler Baker
// p4.cpp

#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Student.h"

using namespace std;

int main()
{
	Heap<Student> heap;
	string filename, fileLine, token;
	unsigned long ul;
	float gpa;
	ifstream fileHandle;
	Student student;

	cout << endl << endl;
	cout << "Enter a filename: ";
	cin >> filename;

	fileHandle.open(filename);

	while(getline(fileHandle, token, ','))
	{		
		ul = stoul(token, nullptr, 0);
		student.setId(ul);
	
		getline(fileHandle,token);
		gpa = stof(token);

		student.setGpa(gpa);
		heap.insert(student);
	}
	
	fileHandle.close();
	cout << endl << endl;

	cout << "The array is ";
	if(heap.empty())
		cout << "empty." << endl << endl;
	else
		cout << "not empty." << endl << endl;
	
	cout << "Printing the array:" << endl;
	cout << "-------------------" << endl;
	heap.print();
	cout << endl << endl;

	cout << "Press enter to continue...";
	cin.get();
	cout << endl << endl;

	cout << "Insert a student with ID=8032 and gpa = 3.21" << endl;
	cout << "--------------------------------------------" << endl;
	student.setId(8032);
	student.setGpa(3.21);
	heap.insert(student);
	heap.print();
	cout << endl << endl;

	cout << "Press enter to continue...";
	cin.get();
	cout << endl << endl;

	cout << "Get the root of the heap:" << endl;
	cout << "-------------------------" << endl;
	cout << heap.getRoot();
	cout << endl << endl;
	
	cout << "Press enter to continue...";
	cin.get();
	cout << endl << endl;

	cout << "Remove the root and print the array:" << endl;
	cout << "------------------------------------" << endl;
	heap.removeRoot();
	heap.print();
	cout << endl << endl;

	cout << "Press enter to continue...";
	cin.get();	
	cout << endl << endl;

	cout << "Sort the array using heap sort function and print the array:" << endl;
	cout << "------------------------------------------------------------" << endl;
	heap.heapSort();
	heap.print();
	cout << endl << endl;

	cout << "Press enter to continue...";
	cin.get();
	cout << endl << endl;
	
	cout << "Remove the root until the heap is empty" << endl;
	cout << "---------------------------------------" << endl;
	while(!heap.empty())
		heap.removeRoot();
	
	cout << "The array is ";
	if(heap.empty())
		cout << "empty." << endl << endl;
	else
		cout << "not empty." << endl << endl;
	
  return 0;

}

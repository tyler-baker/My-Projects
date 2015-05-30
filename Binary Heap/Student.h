// Tyler Baker
// Student.h

#ifndef _STUDENT_
#define _STUDENT_

#include <iostream>
#include <iomanip>
using namespace std;

class Student{

	public:
		Student();
		Student(unsigned idNumIn, float gpaIn);
		bool operator >(const Student &);
		bool operator <(const Student &);
		void setId(unsigned idNumberIn);
		void setGpa(float gpaIn);	
		unsigned getId() const;
		float getGpa() const;
		
		friend ostream& operator<<(ostream& stream, const Student item);
		

	private:
		unsigned idNum;
		float gpa;







};

inline ostream& operator<<(ostream& stream, const Student item)
{
  cout << item.idNum;
	cout << item.gpa << endl;
	return stream;
}

#endif

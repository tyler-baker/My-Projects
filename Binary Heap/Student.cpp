// Tyler Baker
// Student.cpp

#include "Student.h"

Student::Student()
{
	idNum = 0;
	gpa = 0;
}

Student::Student(unsigned idNumIn, float gpaIn)
{
	idNum = idNumIn;
	gpa = gpaIn;
}

void Student::setId(unsigned idNumIn)
{
	idNum = idNumIn;
}

void Student::setGpa(float gpaIn)
{
	gpa = gpaIn;
}

bool Student::operator >(const Student &rhs)
{
	if(gpa > rhs.gpa)
		return true;
	else
		return false;
	return false;

}

bool Student::operator <(const Student &rhs)
{
		if(gpa < rhs.gpa)
			return true;
		else
			return false;
	return false;
}
// GETTERS

unsigned Student::getId() const
{
	return idNum;
}

float Student::getGpa() const
{
	return gpa;
}

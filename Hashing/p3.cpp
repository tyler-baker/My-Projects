// Tyler Baker
// p3.cpp

#include <iostream>
#include <ctime>
#include "Hash.h"

using namespace std;

int main(int argc, const char * argv[])
{
	int NUM_DATA = 1;
	if(argc == 2)
		NUM_DATA = atoi(argv[1]);


	HashMap <int> table(4096);
	for(int i=0; i<NUM_DATA; i++)
		table.put(1+rand()%(RAND_MAX-1), rand());
	clock_t t;
	
	t = clock();
	table.put(1179, 120);
	table.put(9702, 121);
	table.put(7183, 122);
	table.put(50184, 123);
	table.put(4235, 124);
	table.put(644, 125);
	table.put(77, 126);
	table.put(3077, 127);
	table.put(23477, 128);
	table.put(90777, 129);	
	t = clock() - t;



	printf ("It took me %d clocks (%f seconds) for 10 puts.\n",(int)t,(float)(t)/CLOCKS_PER_SEC);
	cout << "123 = " << table.get(50184) << endl;
	cout << "126 = " << table.get(77) << endl;
	cout << "-1 = " << table.get(1) << endl;	// We shouldn't have anything with this key

	
	return 0;
}


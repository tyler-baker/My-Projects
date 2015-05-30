// Tyler Baker
//  Hash.h

#ifndef __hashlab__Hash__
#define __hashlab__Hash__

#include <iostream>
using namespace std;


template <class TYPE> class HashEntry
{
private:
	TYPE key;
	TYPE value;
public:
	HashEntry(TYPE key, TYPE value)
	{
		this->key = key;
		this->value = value;
	}
	
	TYPE getKey()
	{
		return key;
	}
	
	TYPE getValue()
	{
		return value;
	}
};

template <class TYPE> class HashMap
{
private:
	HashEntry <TYPE> **table;
	int TABLE_SIZE;
	int numPuts;

	int hash(int key);
public:
	HashMap(const int size)
	: TABLE_SIZE(size)
	{
		numPuts = 0;
		table = new HashEntry<TYPE>*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = nullptr;
	}
	
	TYPE get(int key);
	

	void put(int key, TYPE value);
	
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != nullptr)
				delete table[i];
		delete[] table;
	}
};

template <class TYPE>
TYPE HashMap<TYPE>::get(int key)
{

	int index = hash(key);
	const int start = index;

	if(index >= 0 && index <= TABLE_SIZE){
		if(table[index] != nullptr && table[index]->getKey() == key)
			return table[index]->getValue();
		else{
			while(index < TABLE_SIZE){
				index++;
				if(table[index] != nullptr && table[index]->getKey() == key)
					return table[index]->getValue();
			}
			index = 0;
			while(index < start){
				if(table[index] != nullptr && table[index]->getKey() == key)
					return table[index]->getKey();
				index++;
			}
		}
	}

	return -1;
}

template <class TYPE>
void HashMap<TYPE>::put(int key, TYPE value)
{
	int index = hash(key);
	const int start = index;

	HashEntry <TYPE>* tempPtr = new HashEntry <TYPE> (key,value);

	if(numPuts < TABLE_SIZE){
		if(table[index] == nullptr){
			table[index] = tempPtr;		
			numPuts++;
		}
		else{
			if(table[index]->getKey() == key)
				table[index] = tempPtr;
			else{
				index++;
				while(table[index] != nullptr && index < TABLE_SIZE
							&& table[index]->getKey() != key)
					index++;
				if(table[index] == nullptr){
					table[index] = tempPtr;
					numPuts++;
				}
				else if(table[index]->getKey() == key)
					table[index] = tempPtr;
				else{
					index = 0;
					while(table[index] != nullptr && index < start)	
						index++;
					if(table[index] == nullptr){
						table[index] = tempPtr;
						numPuts++;
					}
				}
			}
		}
	}
	else
		cout << endl << endl << "Sorry, the table is completely full." << endl;
}

template <class TYPE>
int HashMap<TYPE>::hash(int key){
	return key % TABLE_SIZE;
}
#endif /* defined(__hashlab__Hash__) */

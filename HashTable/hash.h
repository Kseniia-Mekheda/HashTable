#pragma once
#include <iostream>

class HashTable {
public:
	struct Element
	{
		std::string data;
		int key;
		Element* next;

		Element(std::string d = " ", int k = 0, Element* nxt = nullptr) :  data(d), key(k), next(nxt) {}
	};

private:
	static const int tableSize = 10;
	Element* table[tableSize];

	int hashFunction(int key)
	{
		return key % tableSize;
	}

public:
	HashTable()
	{
		for (int i = 0; i < tableSize; ++i)
		{
			table[i] = nullptr;
		}
	}

	void insertInTable(std::string data, int key);

	std::string removeFromTable(int key); 

	std::string findInTable(int key);

	bool isEmpty() const;

	void printHashTable() const;
};

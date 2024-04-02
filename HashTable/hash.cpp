#include "hash.h"

void HashTable::insertInTable(std::string data, int key)
{
	int index = hashFunction(key);
	Element* node = new Element(data, key);

	node->next = table[index];
	table[index] = node;
}

std::string HashTable::removeFromTable(int key)
{
	if (isEmpty())
	{
		return "Table is empty";
	}
	else
	{
		int index = hashFunction(key);
		Element* current = table[index];
		Element* previous = nullptr;

		while (current != nullptr && current->key != key) {
			previous = current;
			current = current->next;
		}

		if (current == nullptr)
		{
			return "No such element found";
		}

		if (previous == nullptr)
		{
			table[index] = current->next;
		}

		else
		{
			previous->next = current->next;
		}

		return current->data;
		delete current;
	}
}

std::string HashTable::findInTable(int key)
{
	if (isEmpty())
	{
		return "Table is empty";
	}
	else
	{
		int index = hashFunction(key);
		Element* current = table[index];

		while (current != nullptr)
		{
			if (current->key == key)
			{
				return current->data;
			}
			current = current->next;
		}

		return "No such element found.";
	}
}

bool HashTable::isEmpty() const
{
	for (int i = 0; i < tableSize; ++i)
	{
		if (table[i] != nullptr)
		{
			return false;
		}
	}

	return true;
}

void HashTable::printHashTable() const
{
	if (isEmpty())
	{
		std::cout << "Table is empty" << std::endl;
		return;
	}
	else
	{
		for (int i = 0; i < tableSize; ++i)
		{
			std::cout << "Bucket " << i << ": ";
			Element* current = table[i];

			while (current != nullptr)
			{
				std::cout << "[" << current->key << ", " << current->data << "] ";
				current = current->next;
			}
			std::cout << std::endl;
		}
	}

}
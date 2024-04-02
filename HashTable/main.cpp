#include "hash.h"
using namespace std;

int main() {
	HashTable H;
	H.insertInTable("Kseniia", 3422);
	H.insertInTable("Ihor", 4000);
	H.insertInTable("Vitaliy", 3241);
	H.insertInTable("Danya", 5647);

	H.printHashTable();
	cout << "Find element with key 3422: " << H.findInTable(3422) << endl;
	cout << "Find element with key 7089: " << H.findInTable(7089) << endl;

	cout << "Remove element from table 4000: " << H.removeFromTable(4000) << endl;
	cout << "Find element that was deleted: " << H.findInTable(4000) << endl;

	cout << "Is table empty: " << H.isEmpty() << endl;

	HashTable Test;
	cout << "Is empty table empty: " << Test.isEmpty() << endl;
	cout << "Find in empty table: " << Test.findInTable(5000) << endl;
	cout << "Remove from empty table: " << Test.removeFromTable(6777) << endl;
	return 0;
}
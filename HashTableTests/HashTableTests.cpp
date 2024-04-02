#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/hash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(HashTableTests)
	{
	public:
		
		TEST_METHOD(IsEmptyTest)
		{
			HashTable H;
			Assert::IsTrue(H.isEmpty());

			H.insertInTable("name", 5677);
			Assert::IsFalse(H.isEmpty());
		}

		TEST_METHOD(InsertTest)
		{
			HashTable H;
			H.insertInTable("name", 5677);
			std::string test = "name";

			Assert::AreEqual(test, H.findInTable(5677));
			Assert::IsFalse(H.isEmpty());
		}

		TEST_METHOD(RemoveTest)
		{
			HashTable H;
			H.insertInTable("name", 5677);
			H.insertInTable("name2", 5457);
			std::string test = "name";

			Assert::AreEqual(test, H.removeFromTable(5677));

			std::string output = "No such element found.";
			Assert::AreEqual(H.findInTable(5677), output);
		}

		TEST_METHOD(FindTest)
		{
			HashTable H;
			H.insertInTable("name", 5677);
			H.insertInTable("name2", 5457);
			std::string test = "name";

			Assert::AreEqual(test, H.findInTable(5677));

			std::string output = "No such element found.";
			Assert::AreEqual(output, H.findInTable(7899));
		}
	};
}

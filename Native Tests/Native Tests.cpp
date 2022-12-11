#include "pch.h"
#include "CppUnitTest.h"
#include "Library.h"
#include <queue>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTests
{
	TEST_CLASS(NativeUnitTests)
	{
	public:
		TEST_METHOD(TestingDataSize)
		{
			//had to change Library.sln from .exe to .lib
			Library test;
			Assert::AreEqual(0, test.getRecordSize());
			test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 2015);
			Assert::AreEqual(1, test.getRecordSize());
			test.deleteBook("The Adventures of Tom Sawyer");
			Assert::AreEqual(0, test.getRecordSize());
		}
		TEST_METHOD(TestingQueues)
		{
			//setup the library
			Library test;
			test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 1883);
			test.addBook("The Adventures of Huckleberry Finn", "Mark Twain", 168, 2, 2, 1885);
			test.addBook("A Promised Land", "Barack Obama", 768, 17, 11, 2020);
			Assert::AreEqual(3, test.getRecordSize());
			//testing the getNamesSorted functions queue (ascending order)
			auto tempQueue = test.getNamesSorted();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue.top());
			tempQueue.pop();

			//testing the getDatesSorted functions queue (newest to oldest)
			priority_queue<DateData, vector<DateData>, less<vector<DateData>::value_type>> tempQueue2 = test.getDatesSorted();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue2.top().name);
			tempQueue2.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue2.top().name);
			tempQueue2.pop();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue2.top().name);
			tempQueue2.pop();
		
			//testing the getSizesSorted functions queue (largest to smallest)
			auto tempQueue3 = test.getDatesSorted();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue3.top().name);
			tempQueue3.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue3.top().name);
			tempQueue3.pop();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue3.top().name);
			tempQueue3.pop();
		}
		TEST_METHOD(TestingSearchByAuthor)
		{
			Library test;
			test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 1883);
			test.addBook("The Adventures of Huckleberry Finn", "Mark Twain", 168, 2, 2, 1885);
			test.addBook("A Promised Land", "Barack Obama", 768, 17, 11, 2020);
			unordered_set<std::string> names = test.getBooksByAuthor("Barack Obama");
			Assert::AreEqual(1, int(names.size()));
			Assert::AreEqual(1, int(names.count("A Promised Land")));
			names = test.getBooksByAuthor("Mark Twain");
			Assert::AreEqual(2, int(names.size()));
			Assert::AreEqual(1, int(names.count("The Adventures of Tom Sawyer")));
			Assert::AreEqual(1, int(names.count("The Adventures of Huckleberry Finn")));
		}
	};
}

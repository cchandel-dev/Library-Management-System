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
			test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 1971);
			test.addBook("Harry Potter", "JK Rowling", 3000, 12, 10, 2022);
			test.addBook("The Adventures of Huckleberry Finn", "Mark Twain", 168, 2, 2, 1973);
			test.addBook("A Promised Land", "Barack Obama", 768, 17, 11, 2010);
			Assert::AreEqual(4, test.getRecordSize());
			//testing the getNamesSorted functions queue (ascending order)
			auto tempQueue = test.getNamesSorted();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("Harry Potter"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue.top());
			tempQueue.pop();

			//testing the getDatesSorted functions queue (newest to oldest)
			auto tempQueue2 = test.getDatesSorted();
			std::string temp = tempQueue2.top().name;
			Assert::AreEqual(std::string("Harry Potter"), temp);
			tempQueue2.pop();
			temp = tempQueue2.top().name;
			Assert::AreEqual(std::string("A Promised Land"), temp);
			tempQueue2.pop();
			temp = tempQueue2.top().name;
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), temp);
			tempQueue2.pop();
			temp = tempQueue2.top().name;
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), temp);

			//testing the getSizesSorted functions queue (largest to smallest)
			auto tempQueue3 = test.getSizesSorted();
			temp = tempQueue3.top().name;
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), temp);
			tempQueue3.pop();
			temp = tempQueue3.top().name;
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), temp);
			tempQueue3.pop();
			temp = tempQueue3.top().name;
			Assert::AreEqual(std::string("A Promised Land"), temp);
			tempQueue3.pop();
			temp = tempQueue3.top().name;
			Assert::AreEqual(std::string("Harry Potter"), temp);
			tempQueue3.pop();
		}
		TEST_METHOD(TestingSearch)
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

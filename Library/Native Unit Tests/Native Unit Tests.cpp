#include "pch.h"
#include "CppUnitTest.h"
#include "Library.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTests
{
	TEST_CLASS(NativeUnitTests)
	{
	public:
		TEST_METHOD(TestingCapability) 
		{
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(TestingDataSize)
		{
			Library test;
			Assert::AreEqual(0, test.getRecordSize());
			//test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 2015);
			//Assert::AreEqual(1, test.getRecordSize());
			//test.deleteBook("The Adventures of Tom Sawyer");
			//Assert::AreEqual(0, test.getRecordSize());
			
		}/*
		TEST_METHOD(TestingQueues)
		{
			Library test;
			test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 1883);
			test.addBook("The Adventures of Huckleberry Finn", "Mark Twain", 168, 2, 2, 1885);
			test.addBook("A Promised Land", "Barack Obama", 768, 17, 11, 2020);
			Assert::AreEqual(3, test.getRecordSize());

			//testing the getNamesSorted functions queue (ascending order)
			auto tempQueue = test.getNamesSorted();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue.top());
			tempQueue.pop();

			//testing the getDatesSorted functions queue (newest to oldest)
			auto tempQueue = test.getDatesSorted();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue.top());
			tempQueue.pop();

			//testing the getSizesSorted functions queue (largest to smallest)
			auto tempQueue = test.getDatesSorted();
			Assert::AreEqual(std::string("A Promised Land"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Tom Sawyer"), tempQueue.top());
			tempQueue.pop();
			Assert::AreEqual(std::string("The Adventures of Huckleberry Finn"), tempQueue.top());
			tempQueue.pop();
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
		}*/
	};
}

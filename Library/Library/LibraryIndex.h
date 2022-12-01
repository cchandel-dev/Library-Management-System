#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Book.h"
using namespace std;
class LibraryIndex{
private:
	vector<Book> Library;
	priority_queue<string> sortByName;
	priority_queue<pair<int, string>>sortByDate;
	priority_queue<pair<int, string>>sortBySize;
	unordered_map<string, vector<string>>searchByAuthor;
	unordered_map<string, Book*>searchByName;
public:
	bool addBook() {}
	bool deleteBook() {}
	void printStats() {}
};


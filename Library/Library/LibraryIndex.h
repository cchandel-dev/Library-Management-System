#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "Book.h"
#include <ctime>
using namespace std;
class LibraryIndex{
private:
	unordered_map<std::string, Book> Library;
	priority_queue<string> sortByName;
	priority_queue<pair<tm, string>>sortByDate;
	priority_queue<pair<int, string>>sortBySize;
	unordered_map<string, vector<string>>searchByAuthor;
public:
	bool addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	}
	bool deleteBook(std::string name) {
	}
	std::string printStats() {}
};


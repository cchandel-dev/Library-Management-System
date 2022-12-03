#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "Book.h"
#include <ctime>
using namespace std;
class Library{
private:
	unordered_map<std::string, Book> data;
	priority_queue<string> sortByName;
	priority_queue<pair<tm, string>>sortByDate;
	priority_queue<pair<int, string>>sortBySize;
	unordered_map<string, unordered_set<std::string>>searchByAuthor;
public:
	bool addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	}
	bool deleteBook(std::string name) {
	}
	std::string printStats() {}
	int getRecordSize() { return data.size(); }
	priority_queue<string> getNamesSorted() { return sortByName; }
	priority_queue<pair<tm, string>> getDatesSorted() { return sortByDate; }
	priority_queue<pair<int, string>> getSizesSorted() { return sortBySize; }
	unordered_set<std::string> getBooksByAuthor(std::string authorName) { return searchByAuthor[authorName]; }
};


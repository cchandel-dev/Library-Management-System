#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "Book.h"
#include "DateData.h"
#include "SizeData.h"
#include <ctime>
using namespace std;
struct SizeCompare {
	bool operator()(const SizeData& a, const SizeData& b) const
	{
		return a.size > b.size;
	}
};
struct DateCompare {
	bool operator() (DateData& a, DateData& b) const
	{
		bool output_temp = a.age <  b.age;
		return output_temp;
	}
};
class Library {
private:
	unordered_map<std::string, Book> data;
	priority_queue<string> sortByName;
	priority_queue<DateData, vector<DateData>, DateCompare>sortByDate;
	priority_queue<SizeData, vector<SizeData>, SizeCompare>sortBySize;
	unordered_map<string, unordered_set<std::string>>searchByAuthor;

public:
	bool addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear);
	bool deleteBook(std::string name);
	std::string printStats();
	int getRecordSize(); 
	inline priority_queue<string> getNamesSorted() { return sortByName; }
	inline priority_queue<DateData, vector<DateData>, DateCompare> getDatesSorted() { return sortByDate; }
	inline priority_queue<SizeData, vector<SizeData>, SizeCompare> getSizesSorted() { return sortBySize; }
	inline unordered_set<std::string> getBooksByAuthor(std::string authorName) { return searchByAuthor[authorName]; }
};
#endif
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
inline bool operator< (const SizeData& a, const SizeData& b)
{
	return a.size > b.size;
}
//Overload the > operator.
inline bool operator> (const SizeData& a, const SizeData& b)
{
	return a.size < b.size;
}
//Overload the < operator.
inline bool operator< (const DateData& a, const DateData& b)
{
	DateData temp_a = a;
	DateData temp_b = b;
	return difftime(mktime(&temp_a.age), mktime(&temp_b.age)) < 0;
}
//Overload the > operator.
inline bool operator> (const DateData& a, const DateData& b)
{
	DateData temp_a = a;
	DateData temp_b = b;
	return difftime(mktime(&temp_a.age), mktime(&temp_b.age)) > 0;
}
class Library {
private:
	unordered_map<std::string, Book> data;
	priority_queue<string> sortByName;
	priority_queue<DateData, vector<DateData>, less<vector<DateData>::value_type>>sortByDate;
	priority_queue<SizeData, vector<SizeData>, less<vector<SizeData>::value_type>>sortBySize;
	unordered_map<string, unordered_set<std::string>>searchByAuthor;

public:
	bool addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear);
	bool deleteBook(std::string name);
	std::string printStats();
	int getRecordSize(); 
	inline priority_queue<string> getNamesSorted() { return sortByName; }
	inline priority_queue<DateData, vector<DateData>, less<vector<DateData>::value_type>> getDatesSorted() { return sortByDate; }
	inline priority_queue<SizeData, vector<SizeData>, less<vector<SizeData>::value_type>> getSizesSorted() { return sortBySize; }
	inline unordered_set<std::string> getBooksByAuthor(std::string authorName) { return searchByAuthor[authorName]; }
};
#endif
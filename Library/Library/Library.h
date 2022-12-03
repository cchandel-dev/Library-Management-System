#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "Book.h"
#include <ctime>
using namespace std;


//Define a custom data type.
class DateData
{
public:
	std::tm age;
	std::string name;
	DateData() : name(""), age(tm()) {}
	DateData(std::string chNewName, std::tm nNewAge) :name(chNewName), age(nNewAge) {}
};
class SizeData
{
public:
	int size;
	std::string name;
	SizeData() : name(""), size(0) {}
	SizeData(std::string chNewName, int nNewAge) :name(chNewName), size(nNewAge) {}
};
//Overload the < operator.
bool operator< (const SizeData& a, const SizeData& b)
{
	return a.size > b.size;
}
//Overload the > operator.
bool operator> (const SizeData& a, const SizeData& b)
{
	return a.size < b.size;
}
//Overload the < operator.
bool operator< (const DateData& a, const DateData& b)
{
	DateData temp_a = a;
	DateData temp_b = b;
	return difftime(mktime(&temp_a.age), mktime(&temp_b.age)) < 0;
}
//Overload the > operator.
bool operator> (const DateData& a, const DateData& b)
{
	DateData temp_a = a;
	DateData temp_b = b;
	return difftime(mktime(&temp_a.age), mktime(&temp_b.age)) > 0;
}



class Library{
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
	int getRecordSize() { return data.size(); }
	priority_queue<string> getNamesSorted() { return sortByName; }
	priority_queue<DateData, vector<DateData>, less<vector<DateData>::value_type>> getDatesSorted() { return sortByDate; }
	priority_queue<SizeData, vector<SizeData>, less<vector<SizeData>::value_type>> getSizesSorted() { return sortBySize; }
	unordered_set<std::string> getBooksByAuthor(std::string authorName) { return searchByAuthor[authorName]; }
};

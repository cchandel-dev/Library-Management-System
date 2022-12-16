#ifndef BOOK_H
#define BOOK_H
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
using namespace std;
using namespace std::chrono;
class Book {
private:
	std::string b_name;
	std::string b_author;
	time_point<system_clock, duration<int>> b_publishDate;
	int b_size;
public:
	Book();
	Book(std::string name, std::string author, time_point<system_clock, duration<int>> publishDate, int size);
	inline std::string getName() { return b_name; }
	inline std::string getAuthor() { return b_author; }
	inline time_point<system_clock, duration<int>> getPublishDate() { return b_publishDate; }
	inline int getSize() { return b_size; }
};
inline Book::Book() : b_name(""), b_author(""), b_size(0) {
};
inline Book::Book(std::string name, std::string author, time_point<system_clock, duration<int>> publishDate, int size)
	: b_name(name), b_author(author), b_publishDate(publishDate), b_size(size) {};
#endif
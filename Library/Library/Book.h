#pragma once
#include <string>
using namespace std;
class Book {
private:
	std::string b_name;
	std::string b_author;
	std::tm b_publishDate;
	int b_size;
public:
	Book();
	Book(std::string name, std::string author, std::tm publishDate, int size);
	std::string getName() { return b_name; }
	std::string getAuthor() { return b_author; }
	std::tm getPublishDate() { return b_publishDate; }
	int getSize() { return b_size; }
};
Book::Book() : b_name(""), b_author(""), b_size(0) {
	std::tm inval = tm();
	b_publishDate = inval;
};
Book::Book(std::string name, std::string author, std::tm publishDate, int size)
	: b_name(name), b_author(author), b_publishDate(publishDate), b_size(size) {};
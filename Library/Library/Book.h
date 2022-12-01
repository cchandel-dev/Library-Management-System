#pragma once
#include <string>
using namespace std;
class Book {
private:
	std::string b_name;
	std::string b_author;
	std::string b_picPath;
	int b_publishDate;
	int b_size;
public:
	Book(std::string name, std::string author, std::string picPath, int publishDate, int size) 
		: b_name(name), b_author(author), b_picPath(picPath), b_publishDate(publishDate), b_size(size){}
	std::string getName() { return b_name; }
	std::string getAuthor() { return b_author; }
	std::string getPicPath() { return b_picPath; }
	int getPublishDate() { return b_publishDate; }
	int getSize() { return b_size; }
};
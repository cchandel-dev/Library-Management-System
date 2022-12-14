#include "Library.h"
//Overload the < operator.

bool Library::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	std::tm published = tm();
	published.tm_year = publishYear;
	published.tm_mon = publishMonth;
	published.tm_mday = publishDate;
	data[name] = Book(name, author, published, size);
	Book last = data[name];
	sortByName.push(name);
	sortByDate.push(DateData(name, published));
	sortBySize.push(SizeData(name, size));

	if (searchByAuthor.count(author) == 0) {
		unordered_set<string> temp{ name };
		searchByAuthor[author] = temp;
	}
	else {
		searchByAuthor[author].insert(name);
	}
	return true;
}
bool Library::deleteBook(std::string name) {
	//erase element from searchByAuthor
	std::string authorName = data[name].getAuthor();
	searchByAuthor[authorName].erase(name);
	//remove book from the data
	data.erase(name);
	//erase element from sortByName
	priority_queue<string> temp;
	while (sortByName.top() != name) {
		temp.push(sortByName.top());
		sortByName.pop();
	}
	sortByName.pop();
	while (sortByName.size()) {
		temp.push(sortByName.top());
		sortByName.pop();
	}
	sortByName = temp;
	//erase element from sortByDate
	priority_queue<DateData>temp_time;
	while (sortByDate.top().name != name) {
		temp_time.push(sortByDate.top());
		sortByDate.pop();
	}
	sortByDate.pop();
	while (sortByDate.size()) {
		temp_time.push(sortByDate.top());
		sortByDate.pop();
	}
	sortByDate = temp_time;
	//erase element from sortBySize
	priority_queue<SizeData>temp_size;
	while (sortBySize.top().name != name) {
		temp_size.push(sortBySize.top());
		sortBySize.pop();
	}
	sortBySize.pop();
	while (sortBySize.size()) {
		temp_size.push(sortBySize.top());
		sortBySize.pop();
	}
	sortBySize = temp_size;
	return true;
}

std::string Library::printStats() {
	std::string output;
	output += "There are " + to_string(data.size()) + "books in the Library!";
	return output;
}
int Library::getRecordSize(){ return data.size(); }

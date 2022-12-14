#include "Library.h"
//Overload the < operator.

bool Library::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	publishYear = publishYear < 1970 ? 1970 : publishYear;
	publishYear = publishYear > 2038 ? 2038 : publishYear;
	publishMonth = publishMonth < 0 ? 0 : publishMonth;
	publishMonth = publishMonth > 11 ? 11 : publishMonth;
	publishDate = publishDate < 1 ? 1 : publishDate;
	publishDate = publishDate > 31 ? 31 : publishDate;
	std::tm published;
	published.tm_year = publishYear - 1900;
	published.tm_mon = publishMonth - 1;
	published.tm_mday = publishDate;
	published.tm_hour = 0;
	published.tm_min = 0;
	published.tm_sec = 0;
	data[name] = Book(name, author, mktime(&published), size);
	Book last = data[name];
	sortByName.push(name);
	DateData temp_Date = DateData(name, mktime(&published));
	sortByDate.push(temp_Date);
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
	priority_queue<DateData, vector<DateData>, DateCompare>temp_time;
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
	priority_queue<SizeData, vector<SizeData>, SizeCompare>temp_size;
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

#include "LibraryIndex.h"


bool LibraryIndex::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	if (publishDate > 31 || publishDate < 0 || publishMonth > 12 || publishMonth < 0 || publishYear > now->tm_year)
		return false;
	std::tm published = tm();
	published.tm_year = publishYear;
	published.tm_mon = publishMonth;
	published.tm_mday = publishDate;
	Library[name] = Book(name, author, published, size));
	Book last = Library[name];
	sortByName.push(last.getName());
	sortByDate.push(pair<tm, string>(last.getPublishDate(), last.getName()));
	sortBySize.push(pair<int, string>(last.getSize(), last.getName()));
	if (searchByAuthor.count(last.getAuthor())) {
		vector<string> temp;
		searchByAuthor[last.getAuthor()] = temp;
	}
	else {
		searchByAuthor[last.getAuthor()].push_back(last.getName());
	}
	return true;
}
bool LibraryIndex::deleteBook(std::string name) {
	//erase element from searchByAuthor
	std::string authorName = Library[name].getAuthor();
	for (int i = 0; i < searchByAuthor[authorName].size(); i++) {
		if (searchByAuthor[authorName][i] == name) {
			searchByAuthor[authorName].erase(searchByAuthor[authorName].begin() + i);
		}
	}
	//remove book from the Library
	Library.erase(name);
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
	priority_queue<pair<tm, string>>temp_time;
	while (sortByDate.top().second != name) {
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
	priority_queue<pair<int, string>>temp_size;
	while (sortBySize.top().second != name) {
		temp_size.push(sortBySize.top());
		sortBySize.pop();
	}
	sortBySize.pop();
	while (sortBySize.size()) {
		temp_size.push(sortBySize.top());
		sortBySize.pop();
	}
	sortBySize = temp_size;
}

std::string LibraryIndex::printStats() {
	std::string output;
	output += "There are " + to_string(Library.size()) + "books in the Library!";
	return output;
}
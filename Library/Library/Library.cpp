#include "Library.h"


bool Library::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	if (publishDate > 31 || publishDate < 0 || publishMonth > 12 || publishMonth < 0 || publishYear > now->tm_year)
		return false;
	std::tm published = tm();
	published.tm_year = publishYear;
	published.tm_mon = publishMonth;
	published.tm_mday = publishDate;
	data[name] = Book(name, author, published, size));
	Book last = data[name];
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

std::string Library::printStats() {
	std::string output;
	output += "There are " + to_string(data.size()) + "books in the Library!";
	return output;
}
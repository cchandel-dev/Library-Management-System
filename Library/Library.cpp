#include "Library.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp >
using namespace std;
//Overload the < operator.
bool Library::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	duration<int> days(publishDate + publishMonth * 31 + publishYear * 365);
	time_point<system_clock, duration<int>> tp(days);
	data[name] = Book(name, author, tp, size);

	std::vector<std::string> name_split;
	std::vector<std::string> author_split;
	boost::split(name_split, name, boost::is_any_of(" "));
	boost::split(author_split, author, boost::is_any_of(" "));
	unordered_set<std::string> keys;
	std::move(name_split.begin(), name_split.end(), std::inserter(keys, keys.end()));
	std::move(author_split.begin(), author_split.end(), std::inserter(keys, keys.end()));
	for (auto key : keys) {
		keyword_mappings[key].insert(name);
	}
	Book last = data[name];
	sortByName.push(name);
	DateData temp_Date = DateData(name, tp);
	sortByDate.push(temp_Date);
	sortBySize.push(SizeData(name, size));

	if (searchByAuthor.count(author) == 0) {
		unordered_set<string> temp{ name };
		searchByAuthor[author] = temp;
	}
	else {
		searchByAuthor[author].insert(name);
	}
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
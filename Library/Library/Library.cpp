#include "Library.h"
#pragma warning(disable : 4996)

bool Library::addBook(std::string name, std::string author, int size, int publishDate, int publishMonth, int publishYear) {
	if (size < 0) return false;
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	if (publishDate > 31 || publishDate < 0 || publishMonth > 12 || publishMonth < 0 || publishYear > 2022)
		return false;
	std::tm published = tm();
	published.tm_year = publishYear;
	published.tm_mon = publishMonth;
	published.tm_mday = publishDate;
	data[name] = Book(name, author, published, size);
	Book last = data[name];
	sortByName.push(last.getName());
	sortByDate.push(DateData(last.getName(), last.getPublishDate()));
	sortBySize.push(SizeData(last.getName(), last.getSize()));
	if (searchByAuthor.count(last.getAuthor()) == 0) {
		unordered_set<string> temp;
		searchByAuthor[last.getAuthor()] = temp;
	}
	else {
		searchByAuthor[last.getAuthor()].insert(last.getName());
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
	while (sortByDate.top().name!= name) {
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
using namespace std;
int main(int argc, char* argv[], char* envp[])
{
	//the problem is not with the testing files but instead it's with addBook or with Library - solved
	// still a problem with searchByAuthor
	Library test;
	test.addBook("The Adventures of Tom Sawyer", "Mark Twain", 224, 15, 8, 1883);
	test.addBook("The Adventures of Huckleberry Finn", "Mark Twain", 168, 2, 2, 1885);
	test.addBook("A Promised Land", "Barack Obama", 768, 17, 11, 2020);

	int s = test.getRecordSize();
	auto q1 = test.getDatesSorted();
	auto q2 = test.getSizesSorted();
	auto q3 = test.getNamesSorted();
	auto s1 = test.getBooksByAuthor("Mark Twain");
}
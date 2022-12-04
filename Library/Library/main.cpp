#include "Library.h"
using namespace std;
int main(int argc, char* argv[], char* envp[])
{
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
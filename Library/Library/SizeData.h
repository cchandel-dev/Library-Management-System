#pragma once
#include <string>
class SizeData
{
public:
	int size;
	std::string name;
	SizeData() : name(""), size(0) {}
	SizeData(std::string chNewName, int nNewAge) :name(chNewName), size(nNewAge) {}
};
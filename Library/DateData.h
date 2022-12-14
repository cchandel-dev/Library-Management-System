#pragma once
#include <ctime>
class DateData
{
public:
	std::time_t age;
	std::string name;
	DateData() : name(""), age(std::time_t()) {}
	DateData(std::string chNewName, std::time_t nNewAge) :name(chNewName), age(nNewAge) {}
};
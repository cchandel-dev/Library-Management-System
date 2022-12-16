#pragma once
#include <ctime>
class DateData
{
public:
	time_point<system_clock, duration<int>>  age;
	std::string name;
	DateData(std::string chNewName, time_point<system_clock, duration<int>>  nNewAge) :name(chNewName), age(nNewAge) {}
};
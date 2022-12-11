#pragma once
class DateData
{
public:
	std::tm age;
	std::string name;
	DateData() : name(""), age(tm()) {}
	DateData(std::string chNewName, std::tm nNewAge) :name(chNewName), age(nNewAge) {}
};
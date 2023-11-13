#pragma once
#include<string>
#include <iostream>
class Cs
{
public:
	std::string name = "None";
	int workshops_work = 0;
	friend std::istream& operator>>(std::istream& in, Cs& station);
	friend std::ostream& operator<< (std::ostream& out, Cs& station);
//private:
	int workshops = 0;
	double effect = 0;
};


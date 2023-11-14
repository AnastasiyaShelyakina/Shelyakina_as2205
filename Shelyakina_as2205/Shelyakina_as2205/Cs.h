#pragma once
#include<string>
#include <iostream>
#include <fstream>
class Cs
{
public:
	std::string name = "None";
	int workshops_work = 0;
	int workshops = 0;
	double effect = 0;
	friend std::istream& operator>>(std::istream& in, Cs& station);
	friend std::ostream& operator<< (std::ostream& out, Cs& station);
	friend std::ofstream& operator << (std::ofstream& file, Cs& station);
	friend std::ifstream& operator >> (std::ifstream& fin, Cs& station);
	void Writing_to_file(Cs& station);
	void Read_from_file(Cs& st);

};


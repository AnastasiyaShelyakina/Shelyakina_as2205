#pragma once
#include<string>
#include <iostream>
#include <fstream>
class Cs
{

private:
	int id = 1;
	std::string name = "None";
	int workshops = 0;
	double effect = 0;




public:


	void ChangeStatusCS(Cs& station);
	std::string ReturningTheCSName() const;
	double GetPercentUnused() const;

	static int NextId;
	Cs();
	int GetId() const;
	int workshops_work = 0;
	friend std::istream& operator>>(std::istream& in, Cs& station);
	friend std::ostream& operator<< (std::ostream& out, const Cs& station);
	friend std::ofstream& operator << (std::ofstream& file, const Cs& station);
	friend std::ifstream& operator >> (std::ifstream& file, Cs& station);

};


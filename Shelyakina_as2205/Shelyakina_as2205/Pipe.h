#pragma once
#include <iostream>
#include<string>

class Pipe
{
public:
	std::string name = "None";
	bool repair = false;
	friend std::istream& operator>>(std::istream& in, Pipe& p);
	friend std::ostream& operator<< (std::ostream& out,  Pipe& pipe);
//private:
	double lenght = 0;
	double diametr = 0;


};


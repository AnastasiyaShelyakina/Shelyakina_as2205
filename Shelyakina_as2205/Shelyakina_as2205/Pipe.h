#pragma once
#include <iostream>
#include <fstream>
#include<string>

class Pipe
{
private:
	double lenght = 0;
	double diametr = 0;
	bool repair = false;
public:
	int id = 0;
	std::string name = "None";
	void edit(Pipe& pipe);
	void Writing_to_file(Pipe& pipe);
	void Read_from_file(Pipe& pipe);
	friend std::istream& operator>>(std::istream& in, Pipe& p);
	friend std::ostream& operator<< (std::ostream& out,  Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& file, Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& file, Pipe& pipe);


};


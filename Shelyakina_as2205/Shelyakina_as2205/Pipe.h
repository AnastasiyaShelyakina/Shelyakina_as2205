#pragma once
#include <iostream> 
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Header.h"


class Pipe
{
public:
	static int NextId;
	std::string name = "None";
	bool repair = false;
	Pipe();

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	//friend std::ostream& operator << (std::ostream& out, Pipe& p);
	void edit_Pipe();
	void save_pipe(std::ofstream& file);
	void load_pipe(std::ifstream& file);
	void ShowInfo();
	int get_id() { return id; };


private:
	double lenght = 0.0;
	double diametr = 0.0;
	int id = 0;

};
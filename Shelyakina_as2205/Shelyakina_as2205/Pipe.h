#pragma once
#include <iostream>
#include <fstream>
#include<string>

class Pipe
{
private:
	std::string name = "None";
	double lenght = 0;
	double diametr = 0;
	int id = 1;
	static int NextId;
public:
	bool repair = false;
	//static int NextId;
	Pipe();
	int GetId() const;
	void ChangeStatus(Pipe& pipe);


	std::string GetThePipeName() const;
	static int GetNextId();
	static void SetNextId(int newNextId);



	//std::string ReturningThePipeName() const;
	bool ReturningThePipeRepair() const;
	friend std::istream& operator>>(std::istream& in, Pipe& p);
	friend std::ostream& operator<< (std::ostream& out, const Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& file, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& file, Pipe& pipe);
};


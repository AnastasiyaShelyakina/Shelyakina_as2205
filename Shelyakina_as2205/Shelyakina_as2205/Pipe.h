#pragma once
#include <iostream>
#include <fstream>
#include<string>

class Pipe
{
private:
	std::string name = "None";
	double lenght = 0;
	int diametr = 0;
	int id = 1;
	static int NextId;
	static int pipe_diameters[];
public:

	static int EnterCorrectDiameter();


	bool repair = false;
	Pipe(); 


	int GetDiameter() const;
	void SetDiameter(int d);


	int GetId() const;
	void ChangeStatus(Pipe& pipe);

	std::string GetThePipeName() const;
	static int GetNextId();



	bool ReturningThePipeRepair() const;

	//friend void InitPipe(Pipe& p, bool with_diameter);


	friend std::istream& operator>>(std::istream& in, Pipe& p);
	friend std::ostream& operator<< (std::ostream& out, const Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& file, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& file, Pipe& pipe);
};


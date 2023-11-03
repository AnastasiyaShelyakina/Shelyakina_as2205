#pragma once
#include <iostream> 
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Pipe
{
public:
	static int NextId;
	string name = "None";
	bool repair = false;
	Pipe() {
		id = NextId++;
	}
	friend istream& operator>> (istream& in, Pipe& p);
	friend ostream& operator<< (ostream& out, Pipe& p);
	friend ifstream& operator >> (ifstream& fin, Pipe& p);
	friend ofstream& operator << (ofstream& fout, Pipe& p);
	void edit_Pipe();
	void save_pipe(ofstream& file);
	void load_pipe(ifstream& file);
	int get_id() { return id; };
private:
	double lenght = 0;
	double diametr = 0;
	int id = 0;

};
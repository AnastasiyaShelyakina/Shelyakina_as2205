#include "Pipe.h"

//#include <iostream>


using namespace std;

int Pipe::NextId = 1;

Pipe::Pipe()
{
	id = NextId++;
}


istream& operator>>(istream& in, Pipe& p)
{
	cout << "index:" << p.id;
	cout << "Enter the name of the pipeee: ";
	//cin.clear();
	//cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "Enter the length of the pipe (in kilometers): ";
	p.lenght = getcorrectnumber(0.0, 500.0);

	cout << "Enter the diameter of the pipe (in meters): ";
	p.diametr = getcorrectnumber(0.0, 1400.0);

	cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
	p.repair = getcorrectnumber(0, 1);
	return in;
}
/*
ostream& operator << (ostream& out, const Pipe& pipe) {
	out << "index:" << pipe.id << endl;
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " mm" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
*/

void Pipe::ShowInfo()
{
	cout << "index:" << pipe.id << endl;
	cout << "Pipe name: " << pipe.name << endl;
	cout << "Length: " << pipe.lenght << " km" << endl;
	cout << "Diameter: " << pipe.diametr << " mm" << endl;
	cout << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
}


void Pipe::save_pipe (ofstream& file) {
	file << "Pipe" << endl;
	file << id << endl;
	file << pipe.name << endl;
	file << pipe.lenght << endl;
	file << pipe.diametr << endl;
	file << pipe.repair << endl;
}
void Pipe::load_pipe(ifstream& file) {
	getline(file, pipe.name);
	file >> id;
	file >> pipe.lenght;
	file >> pipe.diametr;
	file >> pipe.repair;
	return file;
}

void Pipe::edit_Pipe() {
	pipe.repair = !pipe.repair;
}


#include "Pipe.h"
#include <iostream>
#include "Header.h"
using namespace std;

int Pipe::NextId=1


istream& operator >>(istream& in, const Pipe& pipe) {
	cout << "Enter the name of the pipeee: ";
	//cin.clear();
	//cin.ignore(INT_MAX, '\n');
	getline(cin, pipe.name);
	cout << "Enter the length of the pipe (in kilometers): ";
	tr.lenght= getcorrectnumber(0.0, 500.0);

	cout << "Enter the diameter of the pipe (in meters): ";
	pipe.diametr= getcorrectnumber(0.0, 1400.0);

	cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
	pipe.repair= getcorrectnumber(0, 1);


	
	return in;
}
ostream& operator <<(ostream& out, const Pipe& pipe) {
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " mm" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
ofstream& operator << (ofstream& file, const Pipe& pipe) {
	file << "Pipe" << endl;
	file << pipe.name << endl;
	file << pipe.lenght << endl;
	file << pipe.diametr << endl;
	file << pipe.repair << endl;
	return file;
}
ifstream& operator >> (ifstream& file, Pipe& pipe) {
	getline(file, pipe.name);
	file >> pipe.lenght;
	file >> pipe.diametr;
	file >> pipe.repair;
	return file;
}

void Pipe::edit_Pipe() {
	pipe.repair = !pipe.repair;
}


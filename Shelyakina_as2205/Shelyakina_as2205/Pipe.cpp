#include "Pipe.h"
#include "utils.h"
using namespace std;


istream& operator>>(istream& in, Pipe& p)
{
	cout << "Enter the name of the pipeeeeeee: ";
	cin.ignore();
	cin >> ws;
	getline(in, p.name);
	cout << "Enter the length of the pipe (in kilometers): ";
	p.lenght = GetCorrectNumber(1.00, 100.00);
	cout << "Enter the diameter of the pipe (in mmeters): ";
	p.diametr = GetCorrectNumber(1.00, 100.00);
	cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
	p.repair = GetCorrectNumber(0, 1);
	return in;
}

ostream& operator <<(ostream& out, const Pipe& pipe) {
	out << "Pipe id: " << pipe.id << endl;
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " mm" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
ofstream& operator << (ofstream& file, const Pipe& pipe) {
	file << pipe.id<< endl;
	file << pipe.name << endl;
	file << pipe.lenght << endl;
	file << pipe.diametr << endl;
	file << pipe.repair << endl;
	return file;
}
ifstream& operator >> (ifstream& file, Pipe& pipe) {
	file>> pipe.id;
	file >> ws;
	getline(file, pipe.name);
	file >> pipe.lenght;
	file >> pipe.diametr;
	file >> pipe.repair;
	return file;
}


int Pipe::GetId()const { return id; }
int Pipe::NextId = 0;
Pipe::Pipe() {
	id = NextId++;
}

void Pipe::ChangeStatus(Pipe& pipe) {
	pipe.repair = !pipe.repair;
}

std::string Pipe::ReturningThePipeName() const
{
	return name;
}



bool Pipe::ReturningThePipeRepair() const
{
	return repair;
}

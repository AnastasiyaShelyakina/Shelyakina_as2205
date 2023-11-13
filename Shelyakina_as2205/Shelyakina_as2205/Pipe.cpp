#include "Pipe.h"
#include "utils.h"
using namespace std;
istream& operator>>(istream& in, Pipe& p)
{
	cout << "Enter the name of the pipe: ";
	getline(in, p.name);
	cout << "Enter the length of the pipe (in kilometers): ";
	p.lenght = GetCorrectNumber(1.00, 100.00);

	cout << "Enter the diameter of the pipe (in mmeters): ";
	p.diametr = GetCorrectNumber(1.00, 100.00);

	cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
	p.repair = GetCorrectNumber(0, 1);
	return in;
}

ostream& operator <<(ostream& out, Pipe& pipe) {
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " mm" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
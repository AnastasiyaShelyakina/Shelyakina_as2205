#include "Cs.h"
#include "utils.h"
using namespace std;

istream& operator>>(istream& in, Cs& station)
{
	cout << "Enter the name of the compressor station : ";
	cin.ignore();
	cin >> ws;
	getline(in, station.name);
	cout << "Enter the number of workshops at the station : ";
	station.workshops = GetCorrectNumber(0, 100);
	cout << "Enter the number of workshops in operation: ";
	station.workshops_work = GetCorrectNumber(0, station.workshops);
	cout << "Enter effect:";
	station.effect = GetCorrectNumber(0.00, 100.00);
	return in;
};

ostream& operator <<(ostream& out,  Cs& station) {
	out << "Compressor station vame: " << station.name << endl;
	out << "Number of workshops:" << station.workshops << endl;
	out << "Number of workshops in operation:" << station.workshops_work << endl;
	out << "Effect: " << station.effect << endl;
	return out;
}
 
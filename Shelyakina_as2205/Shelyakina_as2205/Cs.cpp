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
ofstream& operator << (ofstream& file, Cs& station) {
	file << "Station" << endl;
	file << station.name << endl;
	file << station.workshops << endl;
	file << station.workshops_work << endl;
	file << station.effect << endl;
	return file;
}
ifstream& operator >> (ifstream& fin, Cs& station) {
	getline(fin, station.name);
	fin >> station.workshops;
	fin >> station.workshops_work;
	fin >> station.effect;
	return fin;
}
void Cs::Writing_to_file(Cs& station) {
	ofstream file;
	file.open("lab1.txt");
	if (!file)
		cout << "file is not found" << endl;
	else {
		if (station.workshops > 0)
			file << station << endl;
	}

	file.close();
}
void Cs::Read_from_file(Cs& st)
{
	ifstream fin("lab1.txt");
	if (fin)
	{
		string name_of_cs_or_truba = "";
		while (getline(fin, name_of_cs_or_truba))
		{
			if (name_of_cs_or_truba == "Station")
				fin >> st;
		}

		fin.close();
	}
}
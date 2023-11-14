#include "Pipe.h"
#include "utils.h"
using namespace std;


istream& operator>>(istream& in, Pipe& p)
{
	cout << "Enter the name of the pipeeee: ";
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

ostream& operator <<(ostream& out, Pipe& pipe) {
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " mm" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
ofstream& operator << (ofstream& file, Pipe& pipe) {
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
void Pipe::edit(Pipe& pipe) {
	pipe.repair = !pipe.repair;
}

void Pipe::Writing_to_file(Pipe& pipe) {
	ofstream file;
	file.open("lab1.txt");
	if (!file)
		cout << "file is not found" << endl;
	else {
		if (pipe.lenght > 0)
			file << pipe << endl;
	}

	file.close();
}
void Pipe::Read_from_file(Pipe& pipe)
{
	ifstream fin("lab1.txt");
	if (fin)
	{
		string name_of_cs_or_truba = "";
		while (getline(fin, name_of_cs_or_truba))
		{
			if (name_of_cs_or_truba == "Pipe")
				fin >> pipe;
		}

		fin.close();
	}
}
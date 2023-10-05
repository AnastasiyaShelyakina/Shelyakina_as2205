#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

struct Pipe
{
	string name = "None";
	double lenght = 0;
	int diametr = 0;
	bool repair = false;
};

struct CS
{
	string name = "None";
	int workshops = 0;
	int workshops_work = 0;
	double effect = 0;
};

int Enter_vibor()
{
	cout << "\nChoose an action: ";
	int vibor = -1;
	cin >> vibor;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Choose an action: ";
		cin >> vibor;
	}
	return vibor;
}

double proverka_doub(double& doub)
{
	cin >> doub;
	while (cin.fail() || cin.peek() != '\n' || doub <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Enter double ";
		cin >> doub;
	}
	return doub;
}

int proverka_int(int& inter)
{
	cin >> inter;
	while (cin.fail() || cin.peek() != '\n' || inter <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Enter integer ";
		cin >> inter;
	}
	return inter;
}

bool proverka_bool(bool& bolli)
{
	cin >> bolli;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Enter bool ";
		cin >> bolli;
	}
	return bolli;

}

Pipe enter_truba()
{
	Pipe tr;
	cout << "Enter the name of the pipee: ";
	cin.ignore();
	cin >> ws;
	getline(cin, tr.name);
	cout << "Enter the length of the pipe (in kilometers): ";
	proverka_doub(tr.lenght);

	cout << "Enter the diameter of the pipe (in meters): ";
	proverka_int(tr.diametr);

	cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
	proverka_bool(tr.repair);

	return tr;


};

CS enter_CS()
{
	CS cs;
	cout << "Enter the name of the compressor station : ";
	cin.ignore();
	cin >> ws;
	getline(cin, cs.name);
	cout << "Enter the number of workshops at the station : ";
	proverka_int(cs.workshops);
	cout << "Enter the number of workshops in operation: ";
	proverka_int(cs.workshops_work);
	while (cs.workshops < cs.workshops_work)
	{
		cout << "Enter a smaller value" << endl;
		proverka_int(cs.workshops_work);
	}
	cout << "Enter effect:";
	proverka_doub(cs.effect);
	return cs;
};

void Print_truba(const Pipe& tr)
{
	if ((tr.name) != "None") {
		cout << "Pipe:" << endl;
		cout << "Enter name truba:" << tr.name
			<< "\nEnter lenght:" << tr.lenght
			<< "\nEnter diametr:" << tr.diametr
			<< "\nEnter repair : " << tr.repair << endl;
	}
	else
		cout << "You do not have pipe" << endl;
};

void Print_CS(const CS& cs)
{
	if ((cs.name) != "None") {
		cout << "Station:" << endl;
		cout << "Enter name Cs:" << cs.name
			<< "\nEnter workshops:" << cs.workshops
			<< "\nEnter workshops in work:" << cs.workshops_work
			<< "\nEnter effect: " << cs.effect << endl;
	}
	else
		cout << "You do not have compressor station" << endl;
};

void Writing_to_file(Pipe& pipe, CS& station)
{
	ofstream fout("lab1.txt");
	if ((pipe.name) != "None") {
		cout << "Add information about pipe " << endl;
		fout << "Pipe" << endl;
		fout << pipe.name << endl;
		fout << pipe.lenght << endl;
		fout << pipe.diametr << endl;
		fout << pipe.repair << endl;
	}
	else
		cout << "No information about pipe " << endl;

	if ((station.name) != "None") {
		cout << "Add information about station " << endl;
		fout << "Station" << endl;
		fout << station.name << endl;
		fout << station.workshops << endl;
		fout << station.workshops_work << endl;
		fout << station.effect << endl;
	}
	else
		cout << "No information about station " << endl;
	fout.close();
}

void Read_from_file(Pipe& pipe, CS& station)
{
	ifstream fin("lab1.txt");
	if (fin)
	{
		string name_of_cs_or_truba = "no";
		int p = 0;
		int s = 0;
		while (getline(fin, name_of_cs_or_truba))
		{
			if (name_of_cs_or_truba == "Pipe")
			{
				cout << "Information about pipe:" << endl;
				cout << "\nPipe" << endl;
				getline(fin, pipe.name);
				cout << "Pipe name: " << pipe.name << endl;
				fin >> pipe.lenght;
				cout << "Pipe length: " << pipe.lenght << endl;
				fin >> pipe.diametr;
				cout << "Pipe diameter: " << pipe.diametr << endl;
				fin >> pipe.repair;
				cout << "Pipe repair: " << pipe.repair << endl;
				p += 1;
			}
			if (name_of_cs_or_truba == "Station")
			{
				cout << "Information about Cs:" << endl;
				cout << "\nCompressor station" << endl;
				getline(fin, station.name);
				cout << "Cs name: " << station.name << endl;
				fin >> station.workshops;
				cout << "Number of workshops of the Cs: " << station.workshops << endl;
				fin >> station.workshops_work;
				cout << "Number of workshops in operation of the Cs: " << station.workshops_work << endl;
				fin >> station.effect;
				cout << "CS efficiency: " << station.effect << endl;
				s += 1;
			}
		}

		if (p == 0)
		{
			cout << "No information about pipe." << endl;
		}
		if (s == 0)
		{
			cout << "No information about station." << endl;
		}
	}
	fin.close();
}
//dorabotki
void edit(Pipe& pipe) {
	pipe.repair = !pipe.repair;
}

ostream& operator <<(ostream& out, const Pipe& pipe) {
	out << "Pipe name: " << pipe.name << endl;
	out << "Length: " << pipe.lenght << " km" << endl;
	out << "Diameter: " << pipe.diametr << " meters" << endl;
	out << "Under Repair: " << (pipe.repair ? "in repair" : " not in repair") << endl;
	return out;
}
ostream& operator <<(ostream& out, const CS& station) {
	out << "Compressor station vame: " << station.name << endl;
	out << "Number of workshops:" << station.workshops << endl;
	out << "Number of workshops in operation:" << station.workshops_work << endl;
	out << "Effect: " << station.effect << endl;
	return out;
}
int main()
{
	Pipe pipe;
	CS station;
	while (true)
	{
		cout << "Menu:" << endl;
		cout << "1. Add Pipe" << endl;
		cout << "2. Add Compressor Station" << endl;
		cout << "3. View all objects" << endl;
		cout << "4. Edit Pipe" << endl;
		cout << "5. Edit Compressor Station" << endl;
		cout << "6. Save" << endl;
		cout << "7. Load" << endl;
		cout << "8. Exit" << endl;
		switch (Enter_vibor())
		{
		case 1:
		{
			if ((pipe.name) == "None") {
				cout << "1. Add pipe" << endl;
				pipe = enter_truba();
			}
			else
				cout << "You have already entered the pipe" << endl;
			break;
		}
		case 2:
		{
			if ((station.name) == "None") {
				cout << "2. Add Cs" << endl;
				station = enter_CS();
			}
			else
				cout << "You have already entered the station" << endl;
			break;
		}
		case 3:
		{
			cout << "3. View all object" << endl;
			if ((pipe.name) != "None") {
				cout << pipe << endl;
			}
			else
				cout << "You do not have pipe" << endl;
			if ((station.name) != "None") {
				cout << station << endl;
			}
			else
				cout << "You do not have station" << endl;
			break;
		}
		case 4:
		{
			if ((pipe.name) != "None") {
				edit(pipe);
			}
			else
				cout << " You do not have a pipe" << endl;
			break;
		}
		case 5:
		{
			if ((station.name) != "None") {
				cout << "5. Edit Cs" << endl;
				cout << "Entry the number of workshops ";
				proverka_int(station.workshops_work);
				while (station.workshops < station.workshops_work)
				{
					cout << "Enter a smaller value " << endl;
					proverka_int(station.workshops_work);
				}
			}
			else
				cout << " You do not have a compressor station " << endl;
			break;
		}
		case 6:
		{
			cout << "6. Save" << endl;
			Writing_to_file(pipe, station);
			break;
		}
		case 7:
		{
			cout << "7. Dowload" << endl;
			Read_from_file(pipe, station);
			break;
		}
		case 8:
		{
			cout << "8. Exit" << endl;
			return false;
		}
		default:
		{
			cout << "Entry a number from  1 to 8 " << endl;
			break;
		}
		}
	}
	return 0;
}
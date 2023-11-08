#include "Header.h"
#include "Pipe.h"

using namespace std;
unordered_map<int, Pipe> pipe_group;



//struct Pipe
//{
//	string name = "None";
//	double lenght = 0;
//	double diametr = 0;
//	bool repair = false;
//};

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

double vvod_doub(double& doub)
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
double vvod_doubl1(double& doub)
{
	cin >> doub;
	while (cin.fail() || cin.peek() != '\n' || doub <= -1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Enter double ";
		cin >> doub;
	}
	return doub;
}

int vvod_int(int& inter)
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


int vvod_natural(int& inter)
{
	cin >> inter;
	while (cin.fail() || cin.peek() != '\n' || inter <= -1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again \n";
		cout << "Enter integer ";
		cin >> inter;
	}
	return inter;
}

bool vvod_bool(bool& bolli)
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

/*
inline void enter_pipe()
{
	Pipe pipe;
	cin >> pipe;
	pipe_group.insert({ pipe.get_id(),pipe });


}
*/


CS enter_CS()
{
	CS cs;
	cout << "Enter the name of the compressor station : ";
	getline(cin>>ws, cs.name);
	cout << "Enter the number of workshops at the station : ";
	vvod_int(cs.workshops);
	cout << "Enter the number of workshops in operation: ";
	vvod_natural(cs.workshops_work);
	while (cs.workshops < cs.workshops_work)
	{
		cout << "Enter a smaller value" << endl;
		vvod_int(cs.workshops_work);
	}
	cout << "Enter effect:";
	vvod_doubl1(cs.effect);
	return cs;
};


void View(unordered_map<int, Pipe>& pipe_group) {
	for (auto& pipe: pipe_group) {
		pipe.second.ShowInfo();
	}
}

/*
inline void edit(unordered_map<int, Pipe>& pipe_group) {
	int id = getcorrectnumber(0, 10000);
	pipe_group[id].edit_Pipe();
}
*/

/*
ostream& operator <<(ostream& out, const CS& station) {
	out << "Compressor station vame: " << station.name << endl;
	out << "Number of workshops:" << station.workshops << endl;
	out << "Number of workshops in operation:" << station.workshops_work << endl;
	out << "Effect: " << station.effect << endl;
	return out;
}
*/

//void Writing_to_file1(Pipe& pipe)
//{
//	ofstream fout("lab1.txt");
//	if ((pipe.name) != "None") {
//		cout << "Add information about pipe " << endl;
//		fout << "Pipe" << endl;
//		fout << pipe.name << endl;
//		fout << pipe.lenght << endl;
//		fout << pipe.diametr << endl;
//		fout << pipe.repair << endl;
//	}
//	else
//		cout << "No information about pipe " << endl;
//
//	fout.close();
//}
//void Writing_to_file2(CS& station)
//{
//	ifstream fin("lab1.txt");
//	string line;
//	int flag = 0;
//	while (std::getline(fin, line)) {
//		if (line.find("Station") != std::string::npos) {
//			std::cout << "error element est" << std::endl;
//			flag = 1;
//			break;
//		}
//
//	}
//	if (flag == 0){
//		ofstream fout("lab1.txt", ios::app);
//		if ((station.name) != "None") {
//			cout << "Add information about station " << endl;
//			fout << "Station" << endl;
//			fout << station.name << endl;
//			fout << station.workshops << endl;
//			fout << station.workshops_work << endl;
//			fout << station.effect << endl;
//		}
//		else
//			cout << "No information about station " << endl;
//		fout.close();
//
//	}
//
//	fin.close();
//
//
//	
//}


/*
ofstream& operator << (ofstream& file, const CS& station) {
	file << "Station" << endl;
	file << station.name << endl;
	file << station.workshops << endl;
	file << station.workshops_work << endl;
	file << station.effect << endl;
	return file;
}



ifstream& operator >> (ifstream& fin, CS& station) {
	getline(fin, station.name);
	fin >> station.workshops;
	fin >> station.workshops_work;
	fin >> station.effect;
	return fin;
}
*/


/* Временно
void Writing_to_file(unordered_map<int, Pipe>& pipe_group, CS& station) {
	ofstream file;
	file.open("lab1.txt");
	if (!file)
		cout << "file is not found" << endl;
	else {
		//if (pipe.lenght>0)
			file << pipe_group << endl;
		//if (station.workshops>0)
			file << station << endl;
	}

	file.close();
}
void Read_from_file(unordered_map<int, Pipe>& pipe_group, CS& st)
{
	ifstream fin("lab1.txt");
	if (fin)
	{
		string name_of_cs_or_truba="";
		while (getline(fin, name_of_cs_or_truba))
		{
			if (name_of_cs_or_truba == "Pipe")
				fin >> pipe_group;
			else  if (name_of_cs_or_truba == "Station")
				fin >> st;
		}

		fin.close();
	}
}
*/
int main()
{
	//Pipe pipe = {};
	CS station = {};
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
			//enter_pipe();
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
			View(pipe_group);
			/*
			if ((station.name) != "None") {
				cout << station << endl;
			}
			else
				cout << "You do not have station" << endl;
				*/
			break;
		}
		case 4:
		{
			//edit(pipe_group);

			break;
		}
		case 5:
		{
			if ((station.name) != "None") {
				cout << "5. Edit Cs" << endl;
				cout << "Entry the number of workshops ";
				vvod_int(station.workshops_work);
				while (station.workshops < station.workshops_work)
				{
					cout << "Enter a smaller value " << endl;
					vvod_int(station.workshops_work);
				}
			}
			else
				cout << " You do not have a compressor station " << endl;
			break;
		}
		/* Коменчу на время
		case 6:
		{
			cout << "6. Save" << endl;
			Writing_to_file(pipe_group, station);
			break;
		}
		case 7:
		{
			cout << "7. Dowload" << endl;
			Read_from_file(pipe_group, station);
			break;
		}
		*/
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
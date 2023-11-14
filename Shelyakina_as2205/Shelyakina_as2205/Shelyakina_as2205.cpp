#include <iostream> 
#include <fstream>
#include <string>
#include "Cs.h"
#include "Pipe.h"
#include "utils.h"


using namespace std;

int main()
{
	Pipe pipe = {};
	Cs station = {};
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
		switch (GetCorrectNumber(1,8))
		{
		case 1:
		{
			if ((pipe.name) == "None") {
				cout << "1. Add pipe" << endl;
				cin>>pipe;
			}
			else
				cout << "You have already entered the pipe" << endl;
			break;
		}
		case 2:
		{
			if ((station.name) == "None") {
				cout << "2. Add Cs" << endl;
				cin >> station;
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
				pipe.edit(pipe);
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
				station.workshops_work= GetCorrectNumber(0, station.workshops);
			}
			else
				cout << " You do not have a compressor station " << endl;
			break;
		}
	
		case 6:
		{
			cout << "6. Save" << endl;
			pipe.Writing_to_file(pipe);
			station.Writing_to_file(station);
			break;
		}
		case 7:
		{
			cout << "7. Dowload" << endl;
			pipe.Read_from_file(pipe);
			station.Read_from_file(station);

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
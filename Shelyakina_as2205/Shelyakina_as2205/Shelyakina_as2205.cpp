#include <iostream> 
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Cs.h"
#include "Pipe.h"
#include "utils.h"
#include "GusSupplySystem.h"

using namespace std;


int main()

{
	GasSupplySystem GSS;
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
			GSS.Add(GSS.GetPipes());
			break;
		}
		case 2:
		{
			GSS.Add(GSS.GetCS());
			break;
		}
		case 3:
		{
			cout << "3. View all object" << endl;
			GSS.Show();
			break;
		}
		case 4:
		{
			GSS.EditPipe();
			break;
		}
		case 5:
		{
			GSS.EditCS();
			break;
		}
	
		case 6:
		{
			cout << "6. Save" << endl;
			GSS.Writing_to_file();
			cout << "saved successfully" << endl;
			break;
		}
		case 7:
		{
			cout << "7. Dowload" << endl;
			GSS.Read_from_file();
			cout << "load successfully" << endl;
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
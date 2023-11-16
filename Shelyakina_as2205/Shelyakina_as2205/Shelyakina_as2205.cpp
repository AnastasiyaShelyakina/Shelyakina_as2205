#include <iostream> 
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Cs.h"
#include "Pipe.h"
#include "utils.h"
#include "GasTransportationSystem.h"


#include <chrono>
#include <format>
using namespace std::chrono;

using namespace std;


int main()

{
	
	redirect_output_wrapper cerr_out(cerr);
	string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
	ofstream logfile("log_" + time+".txt");
	if (logfile)
		cerr_out.redirect(logfile);
	
	GasTransportationSystem GST;
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
			GST.Add(GST.GetPipes());
			break;
		}
		case 2:
		{
			GST.Add(GST.GetCS());
			break;
		}
		case 3:
		{
			GST.Show();
			break;
		}
		case 4:
		{
			GST.EditPipe();
			break;
		}
		case 5:
		{
			GST.EditCS();
			break;
		}
	
		case 6:
		{
			GST.Writing_to_file();
			cout << "saved successfully" << endl;
			break;
		}
		case 7:
		{
			GST.Read_from_file();
			cout << "load successfully" << endl;
			break;
		}
		
		case 8:
		{
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
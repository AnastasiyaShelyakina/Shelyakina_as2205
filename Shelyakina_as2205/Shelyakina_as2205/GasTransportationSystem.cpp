#include "GasTransportationSystem.h"
using namespace std;
void GasTransportationSystem::Show()
{
	Show(GetPipes());
	Show(GetCS());
}


void GasTransportationSystem::Writing_to_file() {
	ofstream file;
	cout << "Enter the file name: ";
	string line;
	INPUT_LINE(cin, line);
	file.open(line);
	if (!file)
		cout << "file is not found" << endl;
	else {
		file << pipe_map.size() << " " << cs_map.size() << endl;
		for (const auto& [key, pipe] : pipe_map) {
			file << pipe;
		}
		for (const auto& [key, station] : cs_map) {
			file << station;
		}

	}

	file.close();
}
void GasTransportationSystem::Read_from_file() {
	cout << "Enter the file name: ";
	string line;
	INPUT_LINE(cin, line);
	ifstream file;
	file.open(line);
	pipe_map.clear();
	cs_map.clear();
	int num_pipe;
	int num_cs;
	Pipe p;
	Cs cs;
	Pipe::NextId = 0;
	Cs::NextId = 0;

	if (file) {
		file >> num_pipe >> num_cs;
		for (int i = 0; i < num_pipe; i++) {
			file >> p;
			pipe_map.insert({ p.GetId(), p });
			if (p.GetId() > Pipe::NextId)
				Pipe::NextId = p.GetId();
		}
		for (int i = 0; i < num_cs; i++) {
			file >> cs;
			cs_map.insert({ cs.GetId(), cs });
			if (cs.GetId() > Cs::NextId)
				Cs::NextId = cs.GetId();
		}
		Pipe::NextId++;
		Cs::NextId++;
	}
	else {
		cout << "File is not found";
	}
}


void EditOnePipe(unordered_map<int, Pipe>& pipe_map) {
	cout << "Enter ID of pipe (0 - " << Pipe::NextId++ - 1 << "): ";
	int id = GetCorrectNumber(0, Pipe::NextId++ - 1);
	if (pipe_map.count(id) != 0) {
		pipe_map.at(id).ChangeStatus(pipe_map.at(id));
		cout << "Status was changed!\n";
	}
	else
		cout << "Pipe with this ID has not found\n";
}
bool CheckName(const Pipe& p, std::string param)
{
	return (p.ReturningThePipeName().find(param) != std::string::npos);
}
bool ChekByStatus(const Pipe& p, bool param) {
	return (p.ReturningThePipeRepair() == param);
}

bool CheckBySetSize(const std::unordered_set<int>& id_set) {
	if (id_set.size() == 0) {
		std::cout << "Not obects\n";
		return false;
	}
	return true;
}
void ShowObjects(std::unordered_map<int, Pipe>& pipe_map, std::unordered_set<int>& id_set) {
	for (auto& id : id_set) {
		std::cout << pipe_map.at(id);
	}
}
void EditPipes(std::unordered_map<int, Pipe>& pipe_map, std::unordered_set<int>& id_set)
{
	ShowObjects(pipe_map, id_set);
	MenuEditByFilter();
	switch (GetCorrectNumber(0, 3))
	{
	case 1:
	{
		for (auto& id : id_set) {
			pipe_map.at(id).ChangeStatus(pipe_map.at(id));
		}
		std::cout << "Status was changed!\n";
		break;
	}
	case 2:
	{
		for (auto& id : id_set) {
			if ((pipe_map.at(id)).repair == false)
				pipe_map.at(id).ChangeStatus(pipe_map.at(id));
		}
		std::cout << "Status was changed!\n";
		break;
	}
	case 3:
	{
		for (auto& id : id_set) {
			if ((pipe_map.at(id)).repair == true)
				pipe_map.at(id).ChangeStatus(pipe_map.at(id));
		}
		std::cout << "Status was changed!\n";
		break;
	}
	case 0:
	{
		break;
	}
	default:
		break;
	}
}

void EditPackagePipe(unordered_map<int, Pipe>& pipe_map) {
	MenuEditPackageP();
	switch (GetCorrectNumber(0, 2))
	{
	case 1:
	{
		cout << "Enter name of pipe: ";
		unordered_set id_set = FindByFilter(pipe_map, CheckName, EnterLine());
		if (CheckBySetSize(id_set))
			EditPipes(pipe_map, id_set);
		break;
	}
	case 2:
	{
		cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
		unordered_set<int> id_set = FindByFilter(pipe_map, ChekByStatus, bool(GetCorrectNumber(0, 1)));
		if (CheckBySetSize(id_set))
			EditPipes(pipe_map, id_set);
		break;
	}
	case 0:
	{
		break;
	}
	default:
		cout << "Wrong action" << "\n";
		break;
	}
}

void EditAllPipes(std::unordered_map<int, Pipe>& pipe_map)
{
	std::unordered_set<int> id_set;
	for (auto& [key, value] : pipe_map) {
		id_set.insert(key);
	}
	EditPipes(pipe_map, id_set);
}


void DeletePipe(std::unordered_map<int, Pipe>& pipe_map) {
	std::cout << "Enter ID of pipe (0 - " << Pipe::NextId - 1 << "): ";
	int id = GetCorrectNumber(0, Pipe::NextId - 1);
	if (pipe_map.count(id) != 0) {
		pipe_map.erase(id);
		std::cout << "Pipe was deleted!\n";
	}
	else
		std::cout << "Pipe with this ID has not found\n";
}
void GasTransportationSystem::EditPipe()
{
	if (pipe_map.size() != 0) {
		Show(pipe_map);
		MenuEditPipe();
		switch (GetCorrectNumber(0, 4))
		{
		case 1:
		{
			EditOnePipe(pipe_map);
			break;
		}
		case 2:
		{
			EditPackagePipe(pipe_map);
			break;
		}
		case 3:
		{
			EditAllPipes(pipe_map);
			break;
		}
		case 4:
		{
			DeletePipe(pipe_map);
			break;
		}
		case 0:
		{
			break;
		}
		default:
			break;
		}
	}
	else
		cout << "Currently, the system has not pipes!\n";
}





bool CheckCSName(const Cs& cs, std::string name)
{
	return (cs.ReturningTheCSName().find(name) != std::string::npos);
}

bool CheckUnworking(const Cs& cs, double p) {
	return (cs.GetPercentUnused() >= p);
}

void ShowObjectsCS(std::unordered_map<int, Cs>& cs_map, std::unordered_set<int>& id_set) {
	for (auto& id : id_set) {
		std::cout << cs_map.at(id);
	}
}


void EditOneCS(unordered_map<int, Cs>& cs_map) {
	cout << "Enter ID of cs (0 - " << Cs::NextId++ - 1 << "): ";
	int id = GetCorrectNumber(0, Cs::NextId++ - 1);
	if (cs_map.count(id) != 0) {
		cs_map[id].ChangeStatusCS(cs_map[id]);
		cout << "Status was changed!\n";
	}
	else
		cout << "Cs with this ID has not found\n";
}

void EditCss(std::unordered_map<int, Cs>& cs_map, std::unordered_set<int>& id_set)
{
	ShowObjectsCS(cs_map, id_set);
	for (auto& id : id_set)
		if (cs_map.find(id) != cs_map.end()) {
			cs_map[id].ChangeStatusCS(cs_map[id]);
			std::cout << "The number of working shops of the compressor station has been changed\n";
		}
}



void EditPackageCS(unordered_map<int, Cs>& cs_map) {
	MenuEditPackageP();
	switch (GetCorrectNumber(0, 2))
	{
	case 1:
	{
		cout << "Enter name of cs: ";
		unordered_set id_set = FindByFilter(cs_map, CheckCSName, EnterLine());
		if (CheckBySetSize(id_set))
			EditCss(cs_map, id_set);
		break;
	}
	case 2:
	{
		cout << "Enter procent ";
		unordered_set<int> id_set = FindByFilter(cs_map, CheckUnworking, double(GetCorrectNumber(0.0, 100.0)));
		if (CheckBySetSize(id_set))
			EditCss(cs_map, id_set);
		break;
	}
	case 0:
	{
		break;
	}
	default:
		cout << "Wrong action" << "\n";
		break;
	}
}

void EditAllCS(std::unordered_map<int, Cs>& cs_map)
{
	std::unordered_set<int> id_set;
	for (auto& [key, value] : cs_map) {
		id_set.insert(key);
	}
	EditCss(cs_map, id_set);
}

void DeleteCS(std::unordered_map<int, Cs>& cs_map) {
	std::cout << "Enter ID of CS (0 - " << Cs::NextId - 1 << "): ";
	int id = GetCorrectNumber(0, Cs::NextId - 1);
	if (cs_map.count(id) != 0) {
		cs_map.erase(id);
		std::cout << "CS was deleted!\n";
	}
	else
		std::cout << "CS with this ID has not found\n";
}



void GasTransportationSystem::EditCS()
{
	if (cs_map.size() != 0) {
		MenuEditStation();
		switch (GetCorrectNumber(0, 3)) {
		case 1:
		{
			EditOneCS(cs_map);
			break;
		}
		case 2:
		{
			EditPackageCS(cs_map);
			break;
		}
		case 3:
		{
			EditAllCS(cs_map);
			break;
		}
		case 4:
		{
			DeleteCS(cs_map);
			break;
		}
		case 0:
		{
			break;
		}
		default:
			break;
		}

	}
	else
		std::cout << "Currently, the system has not CS!\n";
}





std::unordered_map<int, Pipe>& GasTransportationSystem::GetPipes()
{
	return pipe_map;
}


std::unordered_map<int, Cs>& GasTransportationSystem::GetCS()
{
	return cs_map;
}

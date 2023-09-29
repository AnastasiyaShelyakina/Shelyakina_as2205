#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Pipe {
    string name;
    float length;
    float diameter;
    bool isUnderRepair;
};

struct CompressorStation {
    string name;
    int workshops;
    int workshopsInOperation;
    float efficiency;
};

void addPipe(Pipe & pipes) {
    Pipe pipe;
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) {
            cout << "Enter the name of the pipe: ";
        }
        else {
            pipe.name = input;
            break;
        }
    }

    while (true) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "Enter the length of the pipe (in kilometers): ";
        }
        else {
            try {
                pipe.length = stof(input);
                if (pipe.length <= 0 || pipe.length >= 100000) {
                    cout << "Invalid input. Please enter a correct value." << endl;
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
            }
        }
    }

    while (true) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "Enter the diameter of the pipe (in meters): ";
        }
        else {
            try {
                pipe.diameter = stof(input);
                if (pipe.diameter <= 0 || pipe.diameter >= 100000) {
                    cout << "Invalid input. Please enter a correct value." << endl;
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
            }
        }
    }
    while (true) {
        cout << "Enter the value for pipe repair (0 - not under repair, 1 - under repair): ";
        cin >> pipe.isUnderRepair;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter either 0 or 1." << endl;
        }
        else if (pipe.isUnderRepair != 0 && pipe.isUnderRepair != 1) {
            cout << "Invalid input. Please enter either 0 or 1." << endl;
        }
        else {
            break;
        }
    }


    cout << "Pipe added successfully!" << endl;
}

void addCompressorStation(CompressorStation& compressorStations) {
    CompressorStation cs;
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) {
            cout << "Enter the name of the compressor station: ";
        }
        else {
            cs.name = input;
            break;
        }
    }
    while (true) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "Enter the number of workshops at the station : ";
        }
        else {
            try {
                cs.workshops = stof(input);
                if (cs.workshops <= 0 || cs.workshops >= 200) {
                    cout << "Invalid input. Please enter a correct value." << endl;
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
            }
        }
    }

    while (true) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "Enter the number of workshops in operation: ";
        }
        else {
            try {
                cs.workshopsInOperation = stof(input);
                int zapomny;
                zapomny = cs.workshops + 1;
                if (cs.workshopsInOperation <= 0 || cs.workshopsInOperation >= zapomny) {
                    cout << "Invalid input. Please enter a correct value." << endl;
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
            }
        }
    }

    while (true) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "Enter the efficiency of the station: ";
        }
        else {
            try {
                cs.efficiency = stof(input);
                if (cs.efficiency < 0 || cs.efficiency >= 10000) {
                    cout << "Invalid input. Please enter a correct value." << endl;
                }
                else {
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
            }
        }
    }

    cout << "Compressor station added successfully" << endl;
}

void editPipe(Pipe& pipes) {
    cout << "Change pipe status? (0 - In Operation, 1 - Under Repair): ";
    int choice;
    cin >> choice;
    if (choice == 0) {
        pipes.isUnderRepair = false;
    }
    else if (choice == 1) {
        pipes.isUnderRepair = true;
    }
    else {
        cout << "Invalid choice!" << endl;
        return;
    }

}

void editCompressorStation(vector<CompressorStation>& compressorStations) {
    string csName;
    cout << "Enter the name of the compressor station you want to edit: ";
    cin >> csName;
    bool csFound = false;
    for (int i = 0; i < compressorStations.size(); i++) {
        if (compressorStations[i].name == csName) {
            csFound = true;
            cout << "Current number of workshops in operation at station \"" << compressorStations[i].name << "\": "
                << compressorStations[i].workshopsInOperation << endl;
            cout << "Change number of workshops in operation? ";
            cin >> compressorStations[i].workshopsInOperation;
            cout << "Number of workshops in operation at station \"" << compressorStations[i].name << "\" updated successfully!" << endl;
            break;
        }
    }
    if (!csFound) {
        cout << "Compressor station with that name not found!" << endl;
    }
}

void saveData(vector<Pipe>& pipes, vector<CompressorStation>& compressorStations) {
    ofstream file("data.txt");
    if (file.is_open()) {
        file << "Pipes:" << endl;
        for (const Pipe& pipe : pipes) {
            file << "Name: " << pipe.name << ", Length: " << pipe.length << " km, Diameter: "
                << pipe.diameter << " m, Status: " << (pipe.isUnderRepair ? "Under Repair" : "In Operation") << endl;
        }
        file << "Compressor Stations:" << endl;
        for (const CompressorStation& cs : compressorStations) {
            file << "Name: " << cs.name << ", Workshops: " << cs.workshops
                << ", Workshops in Operation: " << cs.workshopsInOperation << ", Efficiency: "
                << cs.efficiency << endl;
        }
        file.close();
        cout << "Data saved successfully to file data.txt!" << endl;
    }
    else {
        cout << "Unable to open file for saving data!" << endl;
    }
}

void loadData(Pipe& pipes, vector<CompressorStation>& compressorStations) {
    ifstream file("data.txt");
    if (file.is_open()) {
        pipes.clear();
        compressorStations.clear();

        string line;
        string category;
        while (getline(file, line)) {
            if (line == "Pipes:") {
                category = "Pipes";
            }
            else if (line == "Compressor Stations:") {
                category = "Compressor Stations";
            }
            else {
                if (category == "Pipes") {
                    Pipe pipe;
                    pipe.name = line.substr(line.find("Name: ") + 6, line.find(", Length:") - line.find("Name: ") - 6);
                    pipe.length = stof(line.substr(line.find("Length: ") + 8, line.find(" km, Diameter:") - line.find("Length: ") - 8));
                    pipe.diameter = stof(line.substr(line.find("Diameter: ") + 10, line.find(" m, Status:") - line.find("Diameter: ") - 10));
                    pipe.isUnderRepair = line.substr(line.find("Status: ") + 8, line.length() - line.find("Status: ") - 8) == "Under Repair";
                    pipes.push_back(pipe);
                }
                else if (category == "Compressor Stations") {
                    CompressorStation cs;
                    cs.name = line.substr(line.find("Name: ") + 6, line.find(", Workshops:") - line.find("Name: ") - 6);
                    cs.workshops = stoi(line.substr(line.find("Workshops: ") + 12, line.find(", Workshops in Operation:") - line.find("Workshops: ") - 12));
                    cs.workshopsInOperation = stoi(line.substr(line.find("Workshops in Operation: ") + 24, line.find(", Efficiency:") - line.find("Workshops in Operation: ") - 24));
                    cs.efficiency = stof(line.substr(line.find("Efficiency: ") + 13, line.length() - line.find("Efficiency: ") - 13));
                    compressorStations.push_back(cs);
                }
            }
        }

        file.close();
        cout << "Data loaded successfully from file data.txt!" << endl;
    }
    else {
        cout << "Unable to open file for loading data!" << endl;
    }
}

void displayData(const vector<Pipe>& pipes, const vector<CompressorStation>& compressorStations) {
    cout << "Pipes:" << endl;
    for (const Pipe& pipe : pipes) {
        cout << "Name: " << pipe.name << ", Length: " << pipe.length << " km, Diameter: "
            << pipe.diameter << " m, Status: " << (pipe.isUnderRepair ? "Under Repair" : "In Operation") << endl;
    }
    cout << "Compressor Stations:" << endl;
    for (const CompressorStation& cs : compressorStations) {
        cout << "Name: " << cs.name << ", Workshops: " << cs.workshops
            << ", Workshops in Operation: " << cs.workshopsInOperation << ", Efficiency: "
            << cs.efficiency << endl;
    }
}

int main() {
    vector<Pipe> pipes;
    vector<CompressorStation> compressorStations;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Pipe" << endl;
        cout << "2. Add Compressor Station" << endl;
        cout << "3. View all objects" << endl;
        cout << "4. Edit Pipe" << endl;
        cout << "5. Edit Compressor Station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an action: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPipe(pipes);
            break;
        case 2:
            addCompressorStation(compressorStations);
            break;
        case 3:
            displayData(pipes, compressorStations);
            break;
        case 4:
            editPipe(pipes);
            break;
        case 5:
            editCompressorStation(compressorStations);
            break;
        case 6:
            saveData(pipes, compressorStations);
            break;
        case 7:
            loadData(pipes, compressorStations);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
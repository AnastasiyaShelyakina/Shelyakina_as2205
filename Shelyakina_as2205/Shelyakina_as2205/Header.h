#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include "Pipe.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <typename T>
T getcorrectnumber(T min, T max) {
	int x;
	while ((cin >> x).fail() || (x < min) || (x > max)) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}


template <typename T>
ostream& operator<< (ostream& out, unordered_map <int, T>& p) {
	out << "Exiting id: ";
	for (auto& [i, obj] : p) {
		cout << i << " ";
	}
	out << endl;
	return out;
}

template <typename T>
ostream& operator<< (ostream& out, unordered_set<int, T>& p) {
	out << "Exiting id: ";
	for (auto& i : p) {
		cout << i << " ";
	}
	out << endl;
	return out;
}

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Pipe.h"
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

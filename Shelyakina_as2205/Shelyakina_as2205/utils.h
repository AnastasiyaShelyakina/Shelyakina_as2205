#pragma once
#include <string>
#include <iostream> 
#include <unordered_map>
#include <unordered_set>


template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	while ((std::cin >> x).fail()	// check type
		|| std::cin.peek() != '\n'	// is buffer empty (int/float check)
		|| x < min || x > max)		// check range
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Type number (" << min << "-" << max << "):";
	}
	std::cerr << x << std::endl;
	return x;
}
template <typename T>
std::unordered_set<int> SeparateBySpace(std::unordered_map<int, T>& map,
    std::string& line)
{
    std::istringstream s{ line };
    std::unordered_set<int> id_set;
    int substring;
    while (!s.eof()) {
        if (!(s >> substring).fail()) {
            if (map.count(substring) == 1)
                id_set.insert(substring);
        }
        else {
            s.clear();
            s.ignore(10000, ' ');
        }
    }
    return id_set;
}
template <typename T1, typename T2>
using Filter = bool(*)(T1& object, T2 param);

template <typename T1, typename T2>
std::unordered_set<int> FindByFilter(std::unordered_map<int,
    T1>& map, Filter<const T1&, T2> f, T2 param)
{
    std::unordered_set<int> result_set;
    for (auto& [key, object] : map)
    {
        if (f(object, param))
            result_set.insert(key);
    }
    return result_set;
}

std::string EnterLine();
void MenuEditPipe();
void MenuEditPackageP();
void MenuEditByFilter();
void MenuEditStation();
void MenuEditPackageCS();
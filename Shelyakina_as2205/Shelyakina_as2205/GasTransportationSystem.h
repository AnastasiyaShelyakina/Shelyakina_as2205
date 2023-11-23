#pragma once
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Cs.h"
#include "utils.h"
class GasTransportationSystem
{
public:

	template <typename T>
	void Add(std::unordered_map<int, T>& map);
	template <typename T>
	void Show(const std::unordered_map<int, T>& map);
	void Show();
	void Writing_to_file();
	void Read_from_file();
	void EditPipe();
	void EditCS();

	std::unordered_map<int, Pipe>& GetPipes();
	std::unordered_map<int, Cs>& GetCS();

private:
	std::unordered_map<int, Pipe> pipe_map;
	std::unordered_map<int, Cs> cs_map;
};
template<typename T>
inline void GasTransportationSystem::Add(std::unordered_map<int, T>& map)
{
	T object;
	std::cin >> object;
	map.insert({ object.GetId(), object });
}


template<typename T>
inline void GasTransportationSystem::Show(const std::unordered_map<int, T>& map)
{
	for (const auto& [key, object] : map)
	{
		operator << (std::cout, object);
	}
}



#pragma once
#ifndef SEARCH_STATS
#define SEARCH_STATS
#include <iostream>
#include <iomanip>
#include <chrono>

typedef std::chrono::duration<double, std::micro> Micro;
typedef std::chrono::high_resolution_clock HRC;

class SearchStats
{
private:
	bool is_find;
	double total_time;
	std::string name;
public:
	SearchStats(const bool is_find, std::chrono::steady_clock::time_point start_time, std::chrono::steady_clock::time_point end_time, std::string name)
		: is_find(is_find), name(name)
	{
		if (is_find)
			total_time = Micro(end_time - start_time).count();
		else
			total_time = -1;
	}
	double get_total_time() const
	{
		return total_time;
	}
	std::string get_name() const
	{
		return name;
	}
};
#endif
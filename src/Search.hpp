#include "SearchStats.hpp"
#include <vector>

template <typename T>
bool consistent_search(std::vector<T>& data, T value) 
{
    for (int i = 0; i < data.size(); i++)
        if (data[i] == value)
            return true;
    return false;
}

template <typename T>
bool consistent_fast_search(std::vector<T>& data, T value)
{
    data.push_back(value);
    for (int i = 0; true; i++)
    {
        if (data[i] == value)
        {
            if (i < data.size() - 1)
                return true;
            return false;
        }
    }
}

template <typename T>
bool consistent_fastest_search(std::vector<T>& data, T value)
{
    data.push_back(value);
    for (int i = 2; true; )
    {
        if (data[i] == value)
        {
            if (i < data.size() - 1)
                return true;
            return false;
        }
        if (data[i + 1] != value)
            i += 2;
        else
            i++;
    }    
}

template <typename T>
SearchStats search(std::vector<T>& data, T value, bool (*search_func)(std::vector<T>& data, T value), std::string name)
{
    auto start_time = HRC::now();

    bool is_find = search_func(data, value);

    auto end_time = HRC::now();
    return SearchStats(is_find, Micro(end_time - start_time).count(), name);
}

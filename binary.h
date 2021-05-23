#ifndef BINARY_H
#define BINARY_H

#include <string>

template<typename Iter>
class Binary_Search
{
public:
    Binary_Search(Iter begin, Iter end) :
        begin(begin),
        end(end)
    {}

    template<typename T>
    T* find(T val)
    {
        Iter first = begin;
        Iter last = end - 1;

        while (first <= last)
        {
            Iter mid = first + (last - first) / 2;

            if (*mid > val)      last = mid - 1;
            else if (*mid < val) first = mid + 1;
            else                return &(*mid);
        }

        return nullptr;
    }

    inline static const std::string path = "benchmarks/binary_search";
    inline static const std::string name = "Binary Search";

private:
    Iter begin;
    Iter end;
};

#endif

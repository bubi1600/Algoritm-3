#ifndef LINEAR_H
#define LINEAR_H

#include <string>

template<typename Iter>
class Linear_Search
{
public:
    Linear_Search(Iter begin, Iter end) :
        begin(begin),
        end(end)
    {}

    template<typename T>
    T* find(T val)
    {
        Iter it = begin;

        while (it++ != end)
        {
            if (*it == val)   return &(*it);
        }

        return nullptr;
    }

    inline static const std::string path = "benchmarks/linear_search";
    inline static const std::string name = "Linear Search";

private:
    Iter begin;
    Iter end;
};

#endif

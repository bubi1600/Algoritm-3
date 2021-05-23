#ifndef ALGORITHMS_H
#define ALGORITHMS_H 

#include <string>


template<typename Iter, typename Val>
Iter binary_search(Iter begin, Iter end, Val val)
{
    Iter first = begin;
    Iter last = end - 1;

    while (first <= last)
    {
        Iter mid = first + (last - first) / 2;

        if (*mid > val)      last = mid - 1;
        else if (*mid < val) first = mid + 1;
        else                return mid;
    }

    return nullptr;
}

struct Linear_Search
{
    template<typename Iter, typename T>
    T* operator()(Iter begin, Iter end, T val)
    {
        while (begin++ != end)
        {
            if (*begin == val)   return &(*begin);
        }

        return nullptr;
    }

    const std::string path = "benchmarks/linear_search";
    const std::string name = "Linear Search";
};

struct Binary_Search
{
    template<typename Iter, typename T>
    T* operator()(Iter begin, Iter end, T val)
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

    const std::string path = "benchmarks/binary_search";
    const std::string name = "Binary Search";
};

struct Binary_Search_Tree
{
    template<typename Iter, typename T>
    T* operator()(Iter begin, Iter end, T val)
    {
        BinarySearchTree<T> tree(begin, end);
        return tree.find(val);
    }

    const std::string path = "benchmarks/binary_search_tree";
    const std::string name = "Binary Search Tree";
};

struct Hash_Table
{
    template<typename Iter, typename T>
    T* operator()(Iter begin, Iter end, T val)
    {
        HashTable<T> table(begin, end);
        return table.find(val);
    }

    const std::string path = "benchmarks/hash_table";
    const std::string name = "Hash Table";
};

#endif

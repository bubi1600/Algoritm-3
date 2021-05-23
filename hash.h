#ifndef HASH_H
#define HASH_H

#include <vector>
#include <memory>
#include <list>
#include <cmath>
#include <string>

template <typename T>
class LinkedList
{
public:
    void push(const T& val)
    {
        if (!first)
        {
            first = std::make_unique<Node>(val);
            last = first.get();
        }
        else
        {
            last->next = std::make_unique<Node>(val);
            last = last->next.get();
        }
    }

    size_t size() const
    {
        size_t size = 0;

        auto it = first.get();
        while (it)
        {
            size++;
            it = it->next.get();
        }

        return size;
    }

    struct Node
    {
        Node(const T data) :
            data(data)
        {}

        T data;
        std::unique_ptr<Node> next = nullptr;
    };

    std::unique_ptr<Node> first = nullptr;
    Node* last = nullptr;
};

template<typename T>
class Hash_Table
{
public:
    template<typename Iter>
    Hash_Table(Iter begin, Iter end)
    {
        hash(begin, end);
    }

    int* find(const int val)
    {
        auto* it = hashtable[val % size].first.get();

        while (it)
        {
            if (it->data == val)   return &it->data;

            it = it->next.get();
        }

        return nullptr;
    }

    inline static const std::string path = "benchmarks/hash_table";
    inline static const std::string name = "Hash Table";

private:
    template<typename Iter>
    void hash(Iter begin, Iter end)
    {
        hashtable.clear();
        hashtable.resize(size);

        auto iter = begin;

        while (++iter != end)
        {
            hashtable[*iter % size].push(*iter);
        }

        const double load = loadFactor();
        //std::cout << load << "\n";
        if (load > 0.5)
        {
            size *= 1.5;

            hash(begin, end);
        }
    }

    double loadFactor()
    {
        size_t nrofentries = 0;

        std::for_each(hashtable.begin(), hashtable.end(), [&nrofentries](LinkedList<T>& list)
            {
                nrofentries += list.size();
            });

        return double(nrofentries) / hashtable.size();
    }

    size_t size = std::pow(10, 6);

    std::vector<LinkedList<T>> hashtable;
};

#endif

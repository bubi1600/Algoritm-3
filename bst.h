#ifndef BST_H
#define BST_H

#include <memory>

template<typename T>
class Binary_Search_Tree
{
public:
    template<typename Iter>
    Binary_Search_Tree(Iter begin, Iter end)
    {
        addNode(begin, end, root);
    }

    T* find(const T val)
    {
        Node* iter = root.get();

        while (iter)
        {
            if (val < iter->data)        iter = iter->left.get();
            else if (val > iter->data)   iter = iter->right.get();
            else                        return &iter->data;
        }

        return nullptr;
    };

    inline static const std::string path = "benchmarks/binary_search_tree";
    inline static const std::string name = "Binary Search Tree";

private:
    struct Node
    {
        Node(const T data) :
            data(data)
        {};

        T data;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;
    };

    std::unique_ptr<Node> root = nullptr;

    template<typename Iter>
    void addNode(Iter begin, Iter end, std::unique_ptr<Node>& node)
    {
        if (begin >= end)    return;

        Iter mid = begin + (end - begin) / 2;

        node = std::make_unique<Node>(*mid);

        addNode(begin, mid, node->left);
        addNode(mid + 1, end, node->right);
    }
};

#endif

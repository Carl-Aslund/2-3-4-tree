#ifndef TREE234_HPP_INCLUDED
#define TREE234_HPP_INCLUDED 1

#include <string>
#include <queue>

using namespace std;

template<type T>
class Tree234Set
{
private:
    class Iterator;

public:
    Tree234Set();
    ~Tree234Set();

    size_t size() const;
    void insert(const T& key);
    bool exists(const T& key) const;
    int height() const;

    void showStatistics(ostream& out) const;
    ostream& print(ostream& out) const;

    using iterator = Iterator;
    iterator begin() const; ///< An iterator that refers to the first element
    iterator end() const;   ///< An invalid / "past-the-end" iterator

private:
    struct Node
    {
        T* keys_;
        size_t numKeys_;
        Node* children_[4];
        bool hasChildren_;
        ~Node();
    };
    Node* root_;

    class Iterator
    {
    public:
        // Definitions that are required for this class to be a well-behaved
        // STL-style iterator that moves forward through a collection of strings.
        using value_type        = T;
        using reference         = value_type&;
        using pointer           = value_type*;
        using difference_type   = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        // Default operations for a forward iterator
        Iterator() = default;
        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;
        ~Iterator() = default;

        // Custom-defined, standard-use iterator operations
        Iterator& operator++();
        T& operator*() const;
        bool operator==(const Iterator& rhs) const;
        bool operator!=(const Iterator& rhs) const;

    private:
        friend class Tree234Set;
        Iterator(Node* current, queue<Node*> queue);
        Node* current_;
        queue<Node*> queue_;
    };
};

#endif //TREE234_SET_HPP INCLUDED

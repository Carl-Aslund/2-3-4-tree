#ifndef TREE234_HPP_INCLUDED
#define TREE234_HPP_INCLUDED 1

#include <string>
#include <queue>

using namespace std;

class Tree234Set
{
private:
    class Iterator;

public:
    Tree234Set();
    ~Tree234Set();

    size_t size() const;
    void insert(const string& key);
    bool exists(const string& key) const;
    int height() const;

    void showStatistics(ostream& out) const;
    ostream& print(ostream& out) const;

    using iterator = Iterator;
    iterator begin() const; ///< An iterator that refers to the first element
    iterator end() const;   ///< An invalid / "past-the-end" iterator

private:
    struct Node
    {
        string keys_[3];
        size_t numKeys_;
        Node* children_[4];
        bool hasChildren_;
        Node(const string& key, Node* leftChild, Node* rightChild);
        ~Node();
    };
    Node* root_;

    // Helper functions for the public methods.
    size_t size(Node* node) const;
    void extendAtRoot();
    void insert(const string& key, Node* node);
    size_t keyIndex(const string& key, Node* node) const;
    bool exists(const string& key, Node* node) const;
    int height(Node* node) const;

    class Iterator
    {
    public:
        // Definitions that are required for this class to be a well-behaved
        // STL-style iterator that moves forward through a collection of strings.
        using value_type        = string;
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
        string& operator*() const;
        bool operator==(const Iterator& rhs) const;
        bool operator!=(const Iterator& rhs) const;

    private:
        friend class Tree234Set;
        Iterator(Node* current, queue<Node*> queue, size_t i);
        Node* current_;
        queue<Node*> queue_;
        size_t index_;
    };
};

#endif //TREE234_SET_HPP INCLUDED

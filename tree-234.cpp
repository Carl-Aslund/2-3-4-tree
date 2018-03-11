#include "tree-234.hpp"

#include <queue>

using namespace std; // TODO: Write header comments for all the functions

/**
    Default constructor for a 234-Tree.
*/
Tree234Set::Tree234Set() : root_{nullptr} { }

/**
    Default destructor for a 234-Tree.
*/
Tree234Set::~Tree234Set()
{
    delete root_;
}

/**
    Getter for the size of the 234-Tree.

    @return a size_t for the number of elements in the tree.
*/
size_t Tree234Set::size() const
{
    return size(root_);
}

/**
    Helper function for size that computes the number of elements in the subtree
    of a particular node.

    @param node a pointer to the root of a tree or subtree
    @return the number of elements in the node and its children
*/
size_t Tree234Set::size(Node* node) const
{
    size_t numElements = numKeys_;
    if (node->hasChildren_)
    {
        for (size_t i = 0; i<(node->numKeys_+1); ++i)
        {
            numElements += size(node->children_[i]);
        }
    }
    return numElements;
}

void Tree234Set::insert(const T& key)
{
    //TODO: Write insert function
}

/**
    If the root of the 234-Tree is a 4-node, that node will be converted into a
    miniature binary tree of 2-nodes.
*/
void Tree234Set::extendAtRoot()
{
    if (root_->numKeys_ < 3)
    {
        cerr << "ERROR: Tried to extend a tree without a 4-node root." << endl;
    }
    else
    {

    }
}

bool Tree234Set::exists(const T& key) const
{
    //TODO: Write exists function
}

/**
    Getter for the height of the 234-Tree.

    @return an int for the height of the tree.
*/
int Tree234Set::height() const
{
    return height(root_);
}

/**
    Helper function for height that computes the height of a tree defined by a
    root node.

    @param node a pointer to the root of a tree or subtree
    @return the height of the tree or subtree
*/
int Tree234Set::height(Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    else if (node->hasChildren_)
    {
        int childSizes[4] = {-1,-1,-1,-1};
        for (size_t i = 0; i<(node->numKeys_+1); ++i)
        {
            childSizes[i] = size(node->children_[i]);
        }
        return 1 + max(childSizes);
    }
    else
    {
        return 0;
    }
}

void Tree234Set::showStatistics(ostream& out) const
{
    //TODO: Write function to output statistics about the tree
}

ostream& Tree234Set::print(ostream& out) const
{
    //TODO: Write function to print the whole tree
}

Tree234Set::iterator Tree234Set::begin() const
{
    //TODO: Write function to obtain an iterator pointing to the first node
}
Tree234Set::iterator Tree234Set::end() const
{
    //TODO: Write function to obtain an iterator to the end of the tree
}

/**
    Default destructor for a Node.
*/
Tree234Set::Node::~Node()
{
    delete[] keys_;
    if (hasChildren_)
    {
        for (size_t i = 0; i<numKeys_+1; ++i)
        {
            delete children_[i];
        }
    }
}

TreeStringSet::Iterator& TreeStringSet::Iterator::operator++()
{
    //TODO: Write iterator incrementer
}

T& TreeStringSet::Iterator::operator*() const
{
    //TODO: Write iterator dereferencing operator
}

bool TreeStringSet::Iterator::operator==(const Iterator& rhs) const
{
    //TODO: Write equality operator
}

bool TreeStringSet::Iterator::operator!=(const Iterator& rhs) const
{
    return !(*this == rhs);
}

TreeStringSet::Iterator::Iterator(Node* current, queue<Node*> queue)
                        : current_{current}, queue_{queue} { }

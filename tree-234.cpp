#include "tree-234.hpp"

#include <queue>

using namespace std; // TODO: Write header comments for all the functions

Tree234Set::Tree234Set() : root_{nullptr} { }

Tree234Set::~Tree234Set()
{
    //TODO: Write destructor
}

size_t Tree234Set::size() const
{
    //TODO: Write size getter
}

void Tree234Set::insert(const T& key)
{
    //TODO: Write insert function
}

bool Tree234Set::exists(const T& key) const
{
    //TODO: Write exists function
}

int Tree234Set::height() const
{
    //TODO: Write height getter
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

Tree234Set::Node::~Node()
{
    //TODO: Write destructor for Node
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
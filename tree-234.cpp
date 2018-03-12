#include "tree-234.hpp"

#include <queue>
#include <iostream>

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
    size_t numElements = node->numKeys_;
    if (node->hasChildren_)
    {
        for (size_t i = 0; i<(node->numKeys_+1); ++i)
        {
            numElements += size(node->children_[i]);
        }
    }
    return numElements;
}

/**
    Inserts an element into the tree.

    @param key the element to be inserted
*/
void Tree234Set::insert(const string& key)
{
    if (root_ == nullptr)
    {
        root_ = new Node{key, nullptr, nullptr};
        root_->hasChildren_ = false;
        return;
    }
    else if (exists(key))
    {
        cerr << "ERROR: Duplicate insertion." << endl;
        return;
    }
    else if (root_->numKeys_ == 3)
    {
        extendAtRoot();
    }
    insert(key, root_);
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
        Node* newRight = new Node{root_->keys_[2], root_->children_[2],
            root_->children_[3]};
        Node* newRoot = new Node{root_->keys_[1], root_, newRight};
        root_->numKeys_ = 1;
        root_->children_[2] = nullptr;
        root_->children_[3] = nullptr;
        root_ = newRoot;
    }
}

/**
    Inserts an element into a tree or subtree defined by a node pointer.

    @param key the element to be inserted
    @param node a pointer to the root of a subtree
*/
void Tree234Set::insert(const string& key, Node* node)
{
    if (node == nullptr)
    {
        cerr << "ERROR: Insertion into nonexistent node." << endl;
        return;
    }
    // The node being pointed to should not be a 4-node, and the key is new
    size_t index = keyIndex(key, node);
    if (node->hasChildren_)
    {
        if (node->children_[index]->numKeys_ == 3)
        {
            // Promotion needed
            Node* promotee = node->children_[index];
            string promoterKey = promotee->keys_[1];
            Node* newRight = new Node{promotee->keys_[2],
                promotee->children_[2], promotee->children_[3]};
            promotee->children_[2] = nullptr;
            promotee->children_[3] = nullptr;
            promotee->numKeys_ = 1;
            // Make space in the parent node for the promoted key
            for (size_t i = node->numKeys_; i>index; --i)
            {
                node->keys_[i] = node->keys_[i-1];
                node->children_[i+1] = node->children_[i];
            }
            node->keys_[index] = promoterKey;
            node->children_[index+1] = newRight;
            ++(node->numKeys_);
            index = keyIndex(key, node);
        }
        insert(key, node->children_[index]);
    }
    else
    {
        // Move over pre-existing keys to make space for the new key
        for (size_t i = node->numKeys_; i>index; --i)
        {
            node->keys_[i] = node->keys_[i-1];
        }
        node->keys_[index] = key;
        ++(node->numKeys_);
    }
}

/**
    Determines before what element index a particular key fits into in a tree.

    @param key the element key in question
    @param node a pointer to the node in question (must not be nullptr)
    @return a size_t referring to the appropriate index for the
*/
size_t Tree234Set::keyIndex(const string& key, Node* node) const
{
    if (node == nullptr)
    {
        cerr << "ERROR: Null target node in indexing." << endl;
        return -1;
    }
    for (size_t i=0; i<node->numKeys_; ++i)
    {
        if (key <= node->keys_[i])
        {
            return i;
        }
    }
    return node->numKeys_; // If the key is the greatest, it goes at the end.
}

/**
    Determines if a particular key can be found in the tree.

    @param key the element key in question
    @return true or false, whether the key is in the tree
*/
bool Tree234Set::exists(const string& key) const
{
    return exists(key, root_);
}

/**
    Determines if a particular key can be found in the tree defined by a root.

    @param key the element key in question
    @param node a pointer to the root of the tree or subtree
    @return true or false, whether the key is in the tree
*/
bool Tree234Set::exists(const string& key, Node* node) const
{
    if (node == nullptr)
    {
        return false;
    }
    size_t index = keyIndex(key, node);
    if (node->keys_[index] == key)
    {
        return true;
    }
    else
    {
        return exists(key, node->children_[index]);
    }
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
        int maxSize = -1;
        for (size_t i = 0; i<(node->numKeys_+1); ++i)
        {
            int childSize = size(node->children_[i]);
            if (childSize > maxSize)
            {
                maxSize = childSize;
            }
        }
        return 1 + maxSize;
    }
    else
    {
        return 0;
    }
}

/**
    Output some potentially useful statistics about the tree.

    @param out the target output stream
*/
void Tree234Set::showStatistics(ostream& out) const
{
    // Format: s size, h height, a 2-nodes, b 3-nodes, c 4-nodes
    out << "Statistics: ";
    out << size() << " size, ";
    out << height() << " height, ";
    out << countNodes(1, root_) << " 2-nodes, ";
    out << countNodes(2, root_) << " 3-nodes, ";
    out << countNodes(3, root_) << " 4-nodes";
    out << endl;
}

/**
    Count how many nodes with a particular number of keys are in the tree.

    @param numKeys the number of keys in targeted nodes
    @param node a pointer to the root of the subtree
    @return the number of nodes with the appropriate number of keys
*/
size_t Tree234Set::countNodes(size_t numKeys, Node* node) const
{
    size_t count = 0;
    if (node == nullptr)
    {
        return count;
    }
    if (node->numKeys_ == numKeys)
    {
        ++count;
    }
    for (size_t i = 0; i<(node->numKeys_+1); ++i)
    {
        count += countNodes(numKeys, node->children_[i]);
    }
    return count;
}

ostream& Tree234Set::print(ostream& out) const
{
    //TODO: Write function to print the whole tree
    //Format:
}

/**
    Creates an iterator pointing to the root of the tree.

    @return an iterator pointing to the beginning of the tree
*/
Tree234Set::iterator Tree234Set::begin() const
{
    if (root_ == nullptr)
    {
        return end();
    }
    else
    {
        queue<Node*> newQueue;
        size_t index = 0;
        if (root_->hasChildren_)
        {
            for (size_t i=0; i<=root_->numKeys_; ++i)
            {
                newQueue.push(root_->children_[i]);
            }
        }
        return Iterator{root_, newQueue, index};
    }
}

/**
    Creates an iterator pointing to nothing.

    @return an iterator pointing to the end of the tree.
*/
Tree234Set::iterator Tree234Set::end() const
{
    return Iterator{};
}

/**
    Parameterized constructor for a 2-Node.

    @param key the only value initially stored in the node
    @param leftChild a node pointer to the first child of the node
    @param rightChild a node pointer to the second child of the node
*/
Tree234Set::Node::Node(const string& key, Node* leftChild, Node* rightChild)
                 : numKeys_{1}, hasChildren_{true}
{
    keys_[0] = key;
    children_[0] = leftChild;
    children_[1] = rightChild;
}

/**
    Default destructor for a Node.
*/
Tree234Set::Node::~Node()
{
    if (hasChildren_)
    {
        for (size_t i = 0; i<numKeys_+1; ++i)
        {
            delete children_[i];
        }
    }
}

/**
    Incrementing operator for a tree iterator.

    @return a reference to the incremented iterator.
*/
Tree234Set::Iterator& Tree234Set::Iterator::operator++()
{
    if (queue_.empty())
    {
        current_ = nullptr;
    }
    else if (index_ < current_->numKeys_-1)
    {
        ++index_;
    }
    else
    {
        index_ = 0;
        Node* next = queue_.front();
        queue_.pop();
        if (next->hasChildren_)
        {
            for (size_t i=0; i<=next->numKeys_; ++i)
            {
                queue_.push(next->children_[i]);
            }
        }
        current_ = next;
    }
    return *this;
}

/**
    Dereferencing operator for a tree iterator.

    @return a reference to the current value of the iterator
*/
string& Tree234Set::Iterator::operator*() const
{
    return current_->keys_[index_];
}

/**
    Equality operator for tree iterators.

    @param rhs a reference to another iterator from the same tree
    @return true or false, whether the iterators are equal
*/
bool Tree234Set::Iterator::operator==(const Iterator& rhs) const
{
    return (current_ == rhs.current_) && (queue_ == rhs.queue_)
        && (index_ == rhs.index_);
}

/**
    Inequality operator for tree iterators.

    @param rhs a reference to another iterator from the same tree
    @return true or false, whether the iterators are unequal
*/
bool Tree234Set::Iterator::operator!=(const Iterator& rhs) const
{
    return !(*this == rhs);
}

/**
    Default constructor for a tree Iterator.

    @param current the input value for the node pointer
    @param queue the input queue
    @param i the initial index of the iterator
*/
Tree234Set::Iterator::Iterator(Node* current, queue<Node*> queue, size_t i)
                        : current_{current}, queue_{queue}, index_{i} { }

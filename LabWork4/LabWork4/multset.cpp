#include<iostream>
#include "multiset.h"

using namespace std;

class MultiSet :: MultiSetImpl
{
public:
    Node *root;
    Node *createNode(int value, int count);
    Node *copyNode(Node *node);
    void deleteNode(Node *&node);
    void push(Node *&node, int value, int count);
    Node *find(Node *&node, int value);
    void addTree(Node *&node);
    void intersect(Node* node, MultiSetImpl &result, MultiSetImpl &set, int &count);
    void difference(Node* node, MultiSetImpl &result, MultiSetImpl &set, int &count);

    MultiSetImpl();
    MultiSetImpl(const MultiSetImpl &set);
    ~MultiSetImpl();
    MultiSetImpl & operator =(const MultiSetImpl &set);
    int find(int value);
};

//=====================================================
// MultiSet
//=====================================================
MultiSet :: MultiSet()
{
    pimpl = new MultiSetImpl();
}

MultiSet :: MultiSet(const MultiSet &set)
{
    pimpl = new MultiSetImpl();
    pimpl -> root = pimpl -> copyNode(set.pimpl -> root);
}

MultiSet :: ~MultiSet()
{
    delete pimpl;
}

MultiSet & MultiSet :: operator =(const MultiSet &set)
{
    if(this == &set)
        return *this;
    pimpl -> deleteNode(pimpl -> root);
    pimpl -> copyNode(set.pimpl -> root);
    return *this;
}

void MultiSet :: push(int value)
{
    pimpl -> push(pimpl -> root, value, 1);
}

int MultiSet :: find(int value)
{
    return pimpl -> find(value);
}

void MultiSet :: add(MultiSet &set, MultiSet &result)
{
    result.pimpl -> root = result.pimpl -> copyNode(pimpl -> root);
    result.pimpl -> addTree(set.pimpl -> root);
}

void MultiSet :: intersect(MultiSet &set, MultiSet &result)
{
    int count;
    pimpl -> intersect(pimpl -> root, *result.pimpl, *set.pimpl, count);
}


void MultiSet :: difference(MultiSet &set, MultiSet &result)
{
    int count;
    pimpl -> difference(pimpl -> root, *result.pimpl, *set.pimpl, count);
}

Node* MultiSet :: getRoot()
{
    return pimpl -> root;
}

//=====================================================
// MultiSetImpl
//=====================================================
MultiSet :: MultiSetImpl :: MultiSetImpl() 
{
    root = NULL;
}

MultiSet :: MultiSetImpl :: MultiSetImpl(const MultiSetImpl &set)
{
    root = copyNode(set.root);
}

MultiSet :: MultiSetImpl :: ~MultiSetImpl()
{
    deleteNode(root);
}

Node* MultiSet :: MultiSetImpl :: createNode(int value, int count)
{
    Node *node = new Node;
    node -> value = value;
    node -> count = count;
    node -> left = 0;
    node -> right = 0;
    return node;
}

Node* MultiSet :: MultiSetImpl :: copyNode(Node *node)
{
    if (!node)
        return 0;

    Node *newNode = new Node;
    newNode -> value = node -> value;
    newNode -> count = node -> count;
    newNode -> left = copyNode(node -> left);
    newNode -> right = copyNode(node -> right);
    return newNode;
}

void MultiSet :: MultiSetImpl :: deleteNode(Node *&node)
{
    if (!node)
        return;

    deleteNode(node -> left);
    deleteNode(node -> right);
    delete node;
    node = 0;
}

MultiSet :: MultiSetImpl& MultiSet :: MultiSetImpl :: operator =(const MultiSetImpl &set)
{
    if(this == &set)
        return *this;
    deleteNode(root);
    copyNode(set.root);
    return *this;
}

void MultiSet :: MultiSetImpl :: push(Node *&node, int value, int count)
{

    if (!node)
    {
        node = createNode(value, 1);
        return;
    }

    if (node -> value == value)
        node -> count += count;
    else if (node -> value > value)
        push(node -> left, value, count);
    else
        push(node -> right, value, count);
}

int MultiSet :: MultiSetImpl :: find(int value)
{   
    Node *node = find(root, value);
    return node ? node -> count : 0;
}

Node* MultiSet :: MultiSetImpl :: find(Node *&node, int value)
{
    if (!node)
        return 0;

    if (node -> value == value)
        return node;

    if (node -> value > value)
        return find(node -> left, value);

    return find(node -> right, value);
}



void MultiSet :: MultiSetImpl :: addTree(Node *&node)
{
    if(!node)
        return;
    push(root, node -> value, node -> count);
    addTree(node -> left);
    addTree(node -> right);
}


void MultiSet :: MultiSetImpl :: intersect(Node* node, MultiSetImpl &result, MultiSetImpl &set, int &count)
{
    if (!node)
        return;
    count = set.find(node -> value);
    cout<< node -> value << " " << node -> count << "/" << count << endl;
    if (count)
        result.push(result.root, node -> value, (count < node -> count) ? count : node -> count);
    intersect(node -> left, result, set, count);
    intersect(node -> right, result, set, count);
}

void MultiSet :: MultiSetImpl :: difference(Node* node, MultiSetImpl &result, MultiSetImpl &set, int &count)
{
    if (!node)
        return;
    count = node -> count - set.find(node -> value);
    if (count > 0)
        result.push(result.root, node -> value, count);
    difference(node -> left, result, set, count);
    difference(node -> right, result, set, count);
}
#pragma once

struct Node
{
    int value;
    int count;
    Node *right, *left;
};

class MultiSet
{
    class MultiSetImpl;
	MultiSetImpl *pimpl;
protected:
    Node* getRoot();
public:
    MultiSet();
    MultiSet(const MultiSet &set);
    ~MultiSet();
    MultiSet & operator =(const MultiSet &set);
    void push(int value);
    int find(int value);
    void add(MultiSet &set, MultiSet &result);
    void intersect(MultiSet &set, MultiSet &result);
    void difference(MultiSet &set, MultiSet &result);
};


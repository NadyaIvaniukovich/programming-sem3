#include<iostream>

using namespace std;

struct Node
{
    int value;
    int count;
    Node *right, *left;
};

class MultiSet
{
    Node *root;
    Node *createNode(int value, int count);
    Node *copyNode(Node *node);
    void deleteNode(Node *&node);
    void push(Node *&node, int value, int count);
    Node *find(Node *&node, int value);
    void print(Node *&node, int level);
    void addTree(Node *&node);
    void intersect(Node* node, MultiSet &result, MultiSet &set, int &count);
    void difference(Node* node, MultiSet &result, MultiSet &set, int &count);
public:
    MultiSet(){ root = NULL; }
    MultiSet(const MultiSet &set);
    ~MultiSet();
    MultiSet & operator =(const MultiSet &set);
    void push(int value);
    int find(int value);
    void print();
    MultiSet add(MultiSet set);
    MultiSet intersect(MultiSet set);
    MultiSet difference(MultiSet set);
};

MultiSet :: MultiSet(const MultiSet &set)
{
    root = copyNode(set.root);
}

MultiSet :: ~MultiSet()
{
    deleteNode(root);
}

Node* MultiSet :: createNode(int value, int count)
{
    Node *node = new Node;
    node -> value = value;
    node -> count = count;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

Node* MultiSet :: copyNode(Node *node)
{
    if (!node)
        return NULL;

    Node *newNode = new Node;
    newNode -> value = node -> value;
    newNode -> count = node -> count;
    newNode -> left = copyNode(node -> left);
    newNode -> right = copyNode(node -> right);
    return newNode;
}

void MultiSet :: deleteNode(Node *&node)
{
    if (!node)
        return;

    deleteNode(node -> left);
    deleteNode(node -> right);
    delete node;
    node = NULL;
}

MultiSet& MultiSet :: operator =(const MultiSet &set)
{
    if(this == &set)
        return *this;
    deleteNode(root);
    copyNode(set.root);
    return *this;
}

void MultiSet :: push(int value)
{
    push(root, value, 1);
}

void MultiSet :: push(Node *&node, int value, int count) 
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

int MultiSet :: find(int value)
{
    Node *node = find(root, value);
    return node ? node -> count : 0;
}

Node* MultiSet :: find(Node *&node, int value)
{
    if (!node)
        return NULL;

    if (node -> value == value)
        return node;

    if (node -> value > value)
        return find(node -> left, value);

    return find(node -> right, value);
}

void MultiSet :: print()
{
    print(root, 0);
}

void MultiSet :: print(Node *&node, int level)
{

    for (int i = 0; i < level - 1; i++)
        cout << "|      ";
    if (level > 0)
        cout << "|______";
    if (!node)
    {
        cout << "null" << endl;
        return;
    }

    cout << node -> value << ":" << node -> count << endl;

    print(node -> left, level + 1);
    print(node -> right, level + 1);
}

void MultiSet :: addTree(Node *&node)
{
    if(!node)
        return;
    push(root, node -> value, node -> count);
    addTree(node -> left);
    addTree(node -> right);
}

MultiSet MultiSet :: add(MultiSet set)
{
    MultiSet result;
    result.root = result.copyNode(root);
    result.addTree(set.root);
    return result;
}

void MultiSet :: intersect(Node* node, MultiSet &result, MultiSet &set, int &count)
{
    if (!node) 
        return;
    count = set.find(node -> value);
    if (count)
        result.push(result.root, node -> value, (count < node -> count) ? count : node -> count);
    intersect(node -> left, result, set, count);
    intersect(node -> right, result, set, count);
}

MultiSet MultiSet :: intersect(MultiSet set)
{
    MultiSet result;
    int count;
    intersect(root, result, set, count);
    return result;
}

void MultiSet :: difference(Node* node, MultiSet &result, MultiSet &set, int &count)
{
    if (!node) 
        return;
    count = node -> count - set.find(node -> value);
    if (count > 0)
        result.push(result.root, node -> value, count);
    difference(node -> left, result, set, count);
    difference(node -> right, result, set, count);
}

MultiSet MultiSet :: difference(MultiSet set)
{
    MultiSet result;
    int count;
    difference(root, result, set, count);
    return result;
}

int main()
{


    MultiSet set1, set2;

    int n = 11, elements[] = {10, 12, 9, 10, 15, 16, 3, 14, 16, 9, 9};
    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0)
            set1.push(elements[i]);
        else 
            set2.push(elements[i]);
    }


    set1.print();
    set2.print();

    MultiSet result = set1.difference(set2);
    result.print();

    cout << set1.find(9) << endl;

    system("pause");
    return 0;
}
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
    void intersect(Node* node, int value, int count);
public:
    MultiSet(){ root = NULL; }
    MultiSet(const MultiSet &set);
    ~MultiSet();
    MultiSet & operator =(const MultiSet &set);
    void push(int value);
    int find(int value);
    void print();
    MultiSet add(MultiSet set);
    void intersect(MultiSet set, MultiSet &result);
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
    if (!root) 
    {
        root = createNode(value, 1);
        return;
    } 
    
    push(root, value, 1);
}

void MultiSet :: push(Node *&node, int value, int count) 
{
    if (node -> value == value)
        node -> count += count;
    else if (node -> value > value)
        if (!node -> left)
            node -> left = createNode(value, count);
        else
            push(node -> left, value, count);
    else 
        if (!node -> right)
            node -> right = createNode(value, count);
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

void MultiSet :: intersect(Node* node, int value, int count)
{
    if (!node)
    {
        createNode(value, count);
        return;
    }

    if (value <= node -> value)
        intersect(node -> left, value, count);
    else
        intersect(node -> right, value, count);
}

void MultiSet :: intersect(MultiSet set, MultiSet &result)
{
    int count;

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

    MultiSet result = set1.add(set2);
    result.print();

    cout << set1.find(9) << endl;

    system("pause");
    return 0;
}
#include<iostream>
#include "multiset.h"

using namespace std;

class ConsoleMultiSet:public MultiSet
{
    void print(Node *&node, int level);
public:
    ConsoleMultiSet(){};
    ~ConsoleMultiSet(){};
    void print();
};

void ConsoleMultiSet :: print()
{
    Node* root = getRoot();
    print(root, 0);
}

void ConsoleMultiSet :: print(Node *&node, int level)
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


int main()
{


    ConsoleMultiSet set1, set2;

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

    ConsoleMultiSet result;
    set1.difference(set2, result);
    result.print();

    cout << set1.find(9) << endl;
    
    system("pause");
    return 0;
}
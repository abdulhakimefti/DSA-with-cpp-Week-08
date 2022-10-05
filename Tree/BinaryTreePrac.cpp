#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int val;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int val)
    {
        this->val = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};
void printTree(treeNode *root, int level);
void spacePrint(int level);
void printTree(treeNode *root, int level)

{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->val << endl;
        return;
    }
    else

    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->val << endl;
    }
    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }
    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value>> left>> right;
        allNodes[i]->val = value;
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid" << endl;
            break;
        }
        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }
        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    printTree(allNodes[0], 0);
}
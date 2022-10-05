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

void preOrderr(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->val);
    preOrderr(root->leftChild, chk);
    preOrderr(root->rightChild, chk);
}
treeNode *buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if (start == end)
    {
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);

    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);
    return newNode;
}
int searchInOrder(int inOrder[], int current, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int preOrder[n];
    int inOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    string chkPre ="";
    preOrderr(root,chkPre);
    cout<<"PreOrder : "<<chkPre<<endl;

}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6



    
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root:0
Left:
    Root:1
    Left:3
    Right:4
Right:
    Root:2
    Left:
        Root:5
        Left:7
        Right:8
    Right:6
*/
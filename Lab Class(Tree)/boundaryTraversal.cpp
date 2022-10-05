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
void printLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if(root->leftChild==NULL&&root->rightChild == NULL){
        cout<<root->val<<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printNonLeavesLeft(treeNode *root)
{
    if (root == NULL)
        return;
     if (root->leftChild != NULL)
    {
        cout << root->val << " ";
        printNonLeavesLeft(root->leftChild);
    }
    else if(root->rightChild!=NULL){
        cout<<root->val<<" ";
        printNonLeavesLeft(root->rightChild);
    }
}

void printNonLeavesRight(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->rightChild != NULL)
    {
        cout << root->val << " ";
        printNonLeavesRight(root->rightChild);
    }
    else if(root->leftChild!=NULL){
        cout<<root->val<<" ";
        printNonLeavesRight(root->leftChild);
    }
}
void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    // LB non leaves
    printNonLeavesLeft(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    // RB leaves
    printLeaves(root->rightChild);
    // RB non leaves
    printNonLeavesRight(root->rightChild);
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
        cin >> value >> left >> right;
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

   boundaryTraversal(allNodes[0]);
   cout<<endl<<endl;

}

/*
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
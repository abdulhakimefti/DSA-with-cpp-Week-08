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
        cout  << root->val << endl;
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
void inOrder(treeNode*root,string &chk){
    if(root==NULL){
        return;
    }

    inOrder(root->leftChild,chk);
    chk+=to_string(root->val);
    inOrder(root->rightChild,chk);  
}
void preOrder(treeNode*root,string &chk){
    if(root==NULL){
        return;
    }
    chk+=to_string(root->val);
    preOrder(root->leftChild,chk);
    preOrder(root->rightChild,chk);  
}
void postOrder(treeNode*root,string &chk){
    if(root==NULL){
        return;
    }

    postOrder(root->leftChild,chk);
    postOrder(root->rightChild,chk);  
    chk+=to_string(root->val);
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

    printTree(allNodes[0], 0);
    string inOrderTraversal = "";
    inOrder(allNodes[0],inOrderTraversal);
    cout<<"InOrder Traversal: "<<inOrderTraversal<<endl;
     string preOrderTraversal = "";
    preOrder(allNodes[0],preOrderTraversal);
    cout<<"PreOrder Traversal: "<<preOrderTraversal<<endl;
     string postOrderTraversal = "";
    postOrder(allNodes[0],postOrderTraversal);
    cout<<"PostOrder Traversal: "<<postOrderTraversal<<endl;
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
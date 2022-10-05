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


int levelOrderTraverSal(treeNode *root, string &chk, int k)
{
    if (root == NULL)
        return -1;
    int max = INT_MIN;
    queue<treeNode *> q;
    int level = 0;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {   
            if(level==k){
                if(max<chkNode->val){
                    max = chkNode->val;
                }
            }
            cout << chkNode->val << " ";
            chk += to_string(chkNode->val);
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
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

   
    string LevelOrderTraversal = "";
    int maxVal = levelOrderTraverSal(allNodes[0], LevelOrderTraversal,2);
    cout << "LevelOrder Traversal: " << LevelOrderTraversal << endl;
    cout<<"Max: "<<maxVal<<endl;
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
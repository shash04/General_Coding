#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

bool isBstUtil(node *root, int min, int max)
{
    if(root == NULL)
        return true;
    if(root->data > min &&
        root->data < max &&
        isBstUtil(root->left, min, root->data) &&
        isBstUtil(root->right, root->data, max))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBinarySearchTree(node* root)
{
    return isBstUtil(root, INT_MIN, INT_MAX);
}
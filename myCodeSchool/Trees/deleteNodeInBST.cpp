#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *findMaxInLeft(node *root)
{
    node *temp = root;
    while (temp->right)
        temp = temp->right;
    return temp;
}

node *deleteNodeInBST(node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = deleteNodeInBST(root->left, data);
    else if (data > root->data)
        root->right = deleteNodeInBST(root->right, data);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (!root->left)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *maxInLeft = findMaxInLeft(root->left);
            root->data = maxInLeft->data;
            root->left = deleteNodeInBST(root->left, maxInLeft->data);
        }
    }
    return root;
}
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *findNode(node *root, int data)
{
    if(root == NULL)
        return NULL;
    if(root->data == data)
        return root;
    else if(data < root->data)
        return findNode(root->left, data);
    else
        return findNode(root->right, data);
}

node* findMin(node *curr)
{
    node *temp;
    while(temp->left)
        temp = temp->left;
    return temp;
}

node *getSuccessor(node *root, int data)
{
    node *current = findNode(root, data, &successor);

    if(current == NULL)
        return NULL;

    // Case 1: If curr has right subtree, successor would be leftmost 
    // node in right subtree
    if(current->right)
    {
        return findMin(curent->right);
    }
    // Case 2: If curr has no right subtree, successor would be deepest
    // ancestor (parent node) having curr in left subtree
    else
    {
        node *ancestor = root;
        node *successor = NULL;
        
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
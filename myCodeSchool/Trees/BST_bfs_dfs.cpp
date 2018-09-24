#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void breadthFirstSearch(node *root)
{
  if(root == NULL)
    return;
  queue<node *> q1;
  q1.push(root);

  while (!q1.empty())
  {
    node *curr = q1.front();
    cout << curr->data << " ";

    if(curr->left)
      q1.push(curr->left);
    if(curr->right)
      q1.push(curr->right);
      
    q1.pop();
  }
}

void depthFirstSearch(node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  depthFirstSearch(root->left);
  depthFirstSearch(root->right);
}
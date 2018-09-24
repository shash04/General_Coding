// BST is as follows
//       5
//   2       8
// 1   3   6   9

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

node *add_node(node *&current_node, int data)
{
  node *new_node = new node();
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  current_node = new_node;
  return current_node;
}

void print_tree(node *root)
{
  if (root == NULL)
    return;
  print_tree(root->left);
  cout << root->data << endl;
  print_tree(root->right);
}

int main()
{
  node *root = NULL;
  root = add_node(root, 5);
  add_node(root->left, 2);
  add_node(root->right, 8);
  add_node(root->left->left, 1);
  add_node(root->left->right, 3);
  add_node(root->right->left, 6);
  add_node(root->right->right, 9);
  // print_tree(root_1);

  depthFirstSearch(root);
  cout << endl;
  breadthFirstSearch(root);
  cout << endl;

  return 0;
}
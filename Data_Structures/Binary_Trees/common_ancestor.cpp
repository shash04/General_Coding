// **********************************************************************************
// PROBLEM: Find the lowest common ancestor in a binary tree 
//       4
//     /   \
//    2     6
//   / \   / \
//  1   3 5   7
// Approach: 
//   1) Create two vectors. Find the nodes in the tree.
//   2) While searching for the nodes, store the path in respective vectors.
//   3) Iterate over both the vectors in reverse order and find common element.
// **********************************************************************************
  
#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
};

node* add_node( node* &current_node, int data )
{
  node* new_node = new node();
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  current_node = new_node;
  return current_node;
}

void print_tree( node* root )
{
  if( root == NULL )
      return;
  print_tree( root->left );
  cout << root->data << endl;
  print_tree( root->right );
}

bool findNode( node* root, int data, vector<node*> &v1 )
{
  if ( root == NULL )
  {
    v1.clear();
    return false;
  }
  v1.push_back( root );
  if( data == root->data ) 
    return true;
  else if( data < root->data )
    return findNode( root->left, data, v1 );
  else 
    return findNode( root->right, data, v1 );
}

void printVector( vector <int> v )
{
  while( !v.empty() )
  {
    cout << v.back()<< endl;
    v.pop_back();
  }
  cout<<endl;
}

node* findCommonAncestor( node* root,int A,int B )
{
  vector<node*> v1, v2;

  // Populate v1 and v2 while finding the nodes. Return false if any of the nodes not found
  if( !( findNode(root, A, v1) && findNode( root, B, v2 ) ) )
    return NULL;
  for( vector<node*>::reverse_iterator it_1=v1.rbegin(); it_1 != v1.rend(); ++it_1 )
  {
    for( vector<node*>::reverse_iterator it_2=v2.rbegin(); it_2 != v2.rend(); ++it_2 )
    {
      if( (*it_1)->data == (*it_2)->data )
        return *it_1;
    }
  }
  return NULL;
}

int main()
{
  node* root_1 = NULL;
  root_1 = add_node( root_1, 4 );
  add_node( root_1->left, 2 );
  add_node( root_1->right, 6 );
  add_node( root_1->left->left, 1 );
  add_node( root_1->left->right, 3 );
  add_node( root_1->right->left, 5 );
  add_node( root_1->right->right, 7 ); 
  print_tree( root_1 );
  
  node* LCA = findCommonAncestor( root_1, 1, 7 );
  if( LCA == NULL )
    cout << "No Lowest Common Ancestor" << endl;
  else
    cout << "Lowest Common Ancestor is = " << LCA->data << endl;

  return 0;
}
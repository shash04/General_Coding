// **************************************************************
// Reverse a linked list using two methods:
// 1. Iterative reversal
// 2. Recursive reversal
// **************************************************************

#include <iostream>

using namespace std;

struct node
{
  int data;
  node* next;
};

node* new_node( int data )
{
  node* temp = new node();
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void add_node( node** head, int data )
{
  if( *head == NULL )
  {
    *head = new_node( data );
    return;
  }
  node* temp = *head;
  while( temp->next != NULL )
    temp = temp->next;
  temp->next = new_node( data );
  return;
}

void print_list( node* head )
{
  if(head == NULL)
    return;
  cout << head->data << endl;
  print_list( head->next );
}

// Function that reverses the linked list iteratively
void iter_rev_list( node** head )
{
  if( *head == NULL )
    return;
  node* current = *head;
  node* prev = NULL;
  while( current != NULL )
  {
    node* next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

// Function that reverses the linked list recursively
void recur_rev_list( node** head )
{
  node* first;
  node* rest;
  if ( *head == NULL ) 
    return;
  first = *head;
  rest = first->next;
  if ( rest == NULL )
    return;
  recur_rev_list( &rest );
  first->next->next = first;
  first->next = NULL;
  *head = rest;
}


int main()
{
  node* head = NULL;
  add_node( &head, 1 );
  add_node( &head, 2 );
  add_node( &head, 3 );
  add_node( &head, 4 );
  cout << "Original list = " << endl;
  print_list( head );
  cout << "After Iterative Recursive = " << endl;
  iter_rev_list( &head );
  print_list( head );
  cout << "After Recursive Reverse = " << endl;
  recur_rev_list( &head );
  print_list( head );
  return 0;
}
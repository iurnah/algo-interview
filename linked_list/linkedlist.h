#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "common.h"
struct node
{	int item; node* next;
	node(int x)
		{ item = x; next = NULL; }
};
typedef node* linkp;

struct Tnode 
{
	int item ;
	Tnode *left;
	Tnode *right;
	Tnode(int x)
	{
		item = x;
		left = NULL;
		right = NULL;
	}
};

void generate_list(linkp head, int n);

void generate_list_v1(linkp& head, int n);

linkp generate_v0(linkp* headRef, int n); 

void generate_v1(linkp* headRef, int n);

void print_item(linkp list);

Tnode* list_to_BST(node * list, int start, int end);

Tnode* list_to_BST_wrapper(node* head);

void BST_in_traversal_recur(Tnode *root);

node *getMiddle(node *left, node **pre_slow);

void list_to_BST_Rui(node *left, node *right, Tnode *root);

void push(linkp* headRef, int item);

int countNodes(node *head);

// TODO: write all those linkedlist functions
// KEY 1: Push() at the head and Push() at the tail. Pay special attention to the
// zero element list.

linkp reverse(linkp x);

void Josephus(int n, int m);

//int length()
//int push()
//int popy()
//int append()

#endif

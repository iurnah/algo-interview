// This is the mian function to demonstrate linked list related functions, those
// function include generate a random linked list generate(data, ne
#include "linkedlist.h"
#include "common.h"

int main()
{	
/*
	//0. initialized random seeds;
	srand(time(NULL));
	//1. demo of generate and print a list
	//node* head = new node(1);
	node* head = new node(0);
	generate_list(head, 3);
	cout << "Generated list: " << endl;
	print_item(head);

	//2. demo of generate_v1 and print a list
	node* head2 = new node(0);
	generate_v1(&head2, 10);
	cout << "Generated list head 2: " << endl;
	print_item(head2);

	//3. demo of using push() to build a list
	//
	node* head3 = new node(0);
	push(&head3, 8);
	cout << "push 8 to void list: " << endl;
	print_item(head3);
	node* head4 = new node(0);
	generate_list(head4, 5);
	cout << "before push: " << endl;
	print_item(head4);
	push(&head4, 7);
	push(&head4, 6);
	push(&head4, 5);
	push(&head4, 4);
	push(&head4, 3);
	push(&head4, 2);
	cout << "push 7 at the begining of list with 5 element: " << endl;
	print_item(head4);

	//TODO: why this is happened?
	//4. demo of generate_v0(), which use push to build a linked list
	//node *head5 = new node(0);
	node *head5 = new node(0);
	head5 = generate_v0(&head5, 5);
	cout << "generate_v0(): " << endl;
	print_item(head5);
*/	
	//5. demo of append a list
	//6. demo of convert a sorted linked list to a well formed binary search tree
	node *head6 = new node(9);
	Tnode *tree_root;
	push(&head6, 8);
	push(&head6, 5);
	push(&head6, 4);
	push(&head6, 3);
	push(&head6, 2);
	push(&head6, 1);
	
	cout << "the testing list is: " << endl;
	print_item(head6);
/*	
	node *pre_mid;
	node *middle = getMiddle(head6, &pre_mid);
	cout << "middle->item" << middle->item << endl;
	cout << "pre_mid->item" << pre_mid->item << endl;
*/	

	Tnode *Troot = list_to_BST_wrapper(head6);
	cout << "debug:: Pass the list_to_BST_wrapper!!! " << endl;
	cout << "the converted binary tree by leetcode" << endl; BST_in_traversal_recur(Troot); /*
	node *curr = head6;
	for(; curr->next != NULL; curr = curr->next);
	cout << "debug:: reached the end of for!!! " << endl;
	list_to_BST_Rui(head6, curr, tree_root);
	cout << "debug:: reached the end of conversion!!! " << endl;
	
	cout << "the converted binary tree by Rui" << endl;
	BST_pre_traversal_recur(tree_root);
*/
}

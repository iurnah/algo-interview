#include "common.h"
#include "linkedlist.h"
//Documents TODO:
//1. unify the method used in build a linked list, all without dummy node.


// generate():	generate a random linked list. In order to use this function,
// a node should be created in the test function, passing the node directly to
// this function will connect the rest of the node by head->next, here we use a
// trick to return the created list to the test function. 
void generate_list(linkp head, int n)
{	
	if(n > 0){
		head->item = rand() % 1000;
		head->next = NULL;
		for (int i = 1; i < n; i++){
			head = head->next = new node(rand() % 1000);	
			cout << head->item << endl;
		}
	}else 
		return;
}

// generate():	generate a random linked list. To use this function, a header
// pointer (node*) should be passed as argument, it doesn't need to be
// initialized. we use pass by reference to modify the passed header pointer, so
// as the created list can return to the test function.
void generate_list_v1(linkp& head, int n)
{	
	linkp head_node = new node(rand() % 1000); 
	head = head_node;
	if(n > 0){
		for (int i = 0; i < n; i++){
			head_node = head_node->next = new node(rand() % 1000);	
			cout << head_node->item << endl;
		}
	}else 
		return;
}

// generate_v0():TODO:	generate a random link list, by calling the push() function
// notice the subtle difference with the generate()
linkp generate_v0(linkp* headRef, int n)
{
	//for(int i=1; i<=n; i++)
		//push(headRef, rand()%1000);
		cout << "begining of the generat_v0(): " << endl;
		push(headRef, 88);
		cout << "*headRef->item = " << (*headRef)->item << endl;
		print_item(*headRef);
		push(headRef, 77);
		cout << "test: " << endl;
		//cout << "*headRef->next->item = " << (*headRef)->next->item << endl;

		cout << "in the generate_v0(): " << endl;
		print_item(*headRef);
	return *headRef;

}

// generate_v1():	generate a random link list, this version is using a strange
// referenece pointer to the head node, but it is also worked, the idea is from
// stanford article about linked list. This is also for a reference function
// here to compare other function in future 
void generate_v1(linkp* headRef, int n)
{	linkp tail = *headRef;	
	tail->item = rand() % 1000;
	cout << "in generate: " << endl;
	cout << tail->item << endl;
	tail->next = NULL;
	for (int i = 1; i < n; i++){
		tail = tail->next = new node(rand() % 1000);	
		cout << tail->item << endl;
	}
	//tail->next = NULL; //don't need it, it include in the constructor
}


// print_item():	Print the item of a linked list passed in by its header
// pointer
void print_item(linkp head)
{	
	for (;head->next != NULL; head=head->next)
		cout << head->item << endl;
	cout << head->item << endl;
}

// push():	Push one element at the begining of a linked list. Use a reference
// pointer refer to the head of the list
void push(linkp* headRef, int item)
{	linkp new_node = new node(item);
	new_node->next = *headRef;
	*headRef = new_node;

/*
	if((*headRef)->next == NULL)
		*headRef = new_node;
	else {
		new_node->next = *headRef;
		*headRef = new_node;
	}
*/
}

// list_to_BST(): convert a linked list to a balanced binary tree
Tnode* list_to_BST(node * list, int start, int end)
{
	if (start > end) return NULL;
	// same as (start+end)/2, avoids overflow
	int mid = start + (end - start) / 2;
	Tnode *leftChild = list_to_BST(list, start, mid - 1);
	Tnode *parent = new Tnode(list->item);
	parent->left = leftChild;
	list = list->next;
	parent->right = list_to_BST(list, mid + 1, end);
	return parent;
}

// list_to_BST_wrapper(): a wapper function for list_to_BST conversion
Tnode* list_to_BST_wrapper(node *head)
{
	int count = countNodes(head);
	return list_to_BST(head, 0, count-1);
}

// BST_in_traversal_recur(): to print out the tree node in order.
void BST_in_traversal_recur(Tnode *root)
{
	if(root == NULL)
		return;

	BST_in_traversal_recur(root->left);	
	cout << root->item << endl;
	BST_in_traversal_recur(root->right);	
}

// countLNodes(): count the total nodes in the linked list
int countNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// getMiddle(): return the pointer point to the mid element
//				modify the passed pre_slow, which is previous element 
//				of mid
//				To find the middle, I use fast walker and slow walker
//				to iterate the list. 
node *getMiddle(node *left, node **pre_slow)
{
	node *fast = left;
	node *slow = left;
	int flag = 0;

	while(fast){
		fast = fast->next;
		flag++;

		if(flag == 2){
			*pre_slow = slow;
			slow = slow->next;
			flag = 0;
		}
	}	

	return slow; 
}

// list_to_BST(): recursively call itself to convert the left sub-tree
//				  and right sub-tree.
//
void list_to_BST_Rui(node *left, node *right, Tnode *root)
{
	node *pre_mid = NULL;
	node *mid = getMiddle(left, &pre_mid); 
	if(mid == right){//for the base case of two nodes.
		root->item = mid->item;
		Tnode *Tleft = new Tnode(left->item);
		root->left = Tleft;
		root->right = NULL;

		return;
	}else if(mid->next == right){//for the base case of three nodes.
		root->item = mid->item;
		Tnode *Tleft = new Tnode(left->item);
		Tnode *Tright = new Tnode(right->item);
		root->left = Tleft;
		root->right = Tright;	

		return;
	}
	
	root->item = mid->item;

	Tnode *root_left = new Tnode(0);	
	Tnode *root_right = new Tnode(0);	
	
	list_to_BST_Rui(left, pre_mid, root_left);	//TODO this should be left to the node before mid 
	list_to_BST_Rui(mid->next, right, root_right);

	root->left = root_left;
	root->right = root_right;

}


//
///*
// * Insertion sort of linked list
// * 
// */
//linkp insertion_sort(linkp a)
//{	node headb(0, 0);
//	linkp u, x, t, b = &headb;
//	for (t = a->next; t != 0; t = u)
//	{	u = t->next; //save t->next, because it will be overwrite later
//		for (x = b; x->next != 0; x = x->next)
//			if (x->next->item > t->item) break;
//		t->next = x->next; 
//		x->next = t;	
//	}
//	a = b;
//	return b;
//}
//
///*
// * Reverse a linked list
// * Interatively reverse a linked list using the left pointer and the right
// * pointerh
// */
//linkp reverse(linkp x)
//{ linkp right, y = x, left = 0;
//  while(y != 0)
//	{	right = y->next;	//save the next, proceed right pointer 
//		y->next = left;		//reverse element y 
//		left = y;			//proced the left to y
//		y = right;			//proceed the y to right,
//	}
//  return left;
//}
//
///*
// * Circular list example:
// *
// * build a circular linked list, with a link from each person to the person on
// * the left in the circle. The integer i represents the ith person in the
// * circle. After building a one-node circular list for 1, we insert 2 through
// * N after that node, resulting in a circle with 1 through N, leaving x
// * pointing to N. Then, we skip M - 1 nodes, beginning with 1, and set the
// * link of the (M - 1)st to skip the Mth, continuing until only one node is left.
// */   
//void Josephus(int n, int m)
//{	int i;
//	linkp t = new node(1, 0); 
//	t->next = t;
//	linkp x = t;
//	for (i = 2; i <= n; i++)
//		x = (x->next = new node(i, t));
//	//x = x->next;
//	while (x != x->next){
//		for (i = 1; i <m; i++) x = x->next;
//		cout << x->next->item << endl;
//		x->next = x->next->next;
//	}
//	cout << x->item << endl;
//}
//

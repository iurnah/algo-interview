#include "common.h"
#include "linkedlist.h"
/*
 * generate a random link list 
 */
linkp generate()
{	

}
/*
 * Interatively reverse a linked list using the left pointer and the right pointer
 */
linkp reverse(linkp x)
{ linkp right, y = x, left = 0;
  while(y != 0)
	{	right = y->next;	//save the next, proceed right pointer 
		y->next = left;		//reverse element y 
		left = y;			//proced the left to y
		y = right;			//proceed the y to right,
	}
  return left;
}

/*
 * Circular list example
 * build a circular linked list, with a link from
 * each person to the person on the left in the circle. The integer i represents the ith person in
 * the circle. After building a one-node circular list for 1, we insert 2 through N after that
 * node, resulting in a circle with 1 through N, leaving x pointing to N. Then, we skip M - 1
 * nodes, beginning with 1, and set the link of the (M - 1)st to skip the Mth, continuing until
 * only one node is left.
 */   
void Josephus(int n, int m)
{	int i;
	linkp t = new node(1, 0); 
	t->next = t;
	linkp x = t;
	for (i = 2; i <= n; i++)
		x = (x->next = new node(i, t));
	//x = x->next;
	while (x != x->next){
		for (i = 1; i <m; i++) x = x->next;
		cout << x->next->item << endl;
		x->next = x->next->next;
	}
	cout << x->item << endl;
}

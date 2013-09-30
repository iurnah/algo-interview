#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "common.h"
struct node
{	int item; node* next;
	node(int x, node* t)
		{ item = x; next = t; }
};

typedef node* linkp;

void generate(linkp a, int n);

linkp insertion_sort(linkp a);

void print_item(linkp list);

linkp reverse(linkp x);

void Josephus(int n, int m);

#endif

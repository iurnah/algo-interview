#include "linkedlist.h"
#include "common.h"

int main()
{	
	
	//2. insertion sort of a random linkedlist
	node list(0,0);
	generate(&list, 5);
	cout << "Generated list: " << endl;
	print_item(&list);
	insertion_sort(&list);
	cout << "insertion sorted list: " << endl;
	print_item(&list);

	//1. test the circular linked list
	//Josephus(9, 5);
}

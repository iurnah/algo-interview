#include "linkedlist.h"
#include "common.h"

int main()
{	
	
	//2. insertion sort of a random linkedlist
	node list(8,0);
	generate(&list, 5);
	cout << "Generated list: " << endl;
	print_item(&list);
	reverse(&list);
	cout << "reverse sorted list: " << endl;
	print_item(&list);
    //cout << "finished !!!" << endl;
	//1. test the circular linked list
	//Josephus(9, 5);
}

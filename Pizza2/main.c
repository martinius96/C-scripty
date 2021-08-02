#include "pizza2.c"
#include <stdio.h>

int main(){
	printf("Zadajte zoznam:\n");
	struct pizza list[LIST_SIZE];
	int list_size = read_pizza_list(list,LIST_SIZE);
	sort_pizza(list,list_size);
    	print_pizza_list(list,list_size);
    	return 0;
}

#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
struct stack* create_stack() {
    	return calloc(1,sizeof(struct stack));
}

void delete_stack(struct stack* stack) {
    	free(stack);
}
/**
 * Ulozenie hodnoty do zasobnika.
 * Funkcia upravi velkost zasobnika a vlozi novu hodnotu.
 *
 * Zabezpecte pomocou funkcie assert aby program spadok ak v zasobniku nie je dost miesta.
 *
 * @arg zasobnik do ktoreho sa ma hodnota ulozit.
 * @arg hodnota, kotra sa ma ulozit.
 */
void  push_stack_value(struct stack* stack,float value) {
	stack->array[stack->size] = value;
    	stack->size += 1;
}

/**
 * Vybratie hodnty zo zasobnika.  Funkcia zmensi velkost zasobnika.
 * Zabezpecte, aby program spadol ka v asobniku nie je doststok hodnot. (velkost nesmie byt mensia ko nula)
 *
 * @arg zasobnik
 *
 * @retrun hodnota na vrchu zasobnika.
 */
float pop_stack_value(struct stack* stack) {
	if (stack->size < 1){
		return -1;
	}else {
        	stack->size--; //zmensi pole o 1
         	return stack->array[stack->size]; //velkost pola
      	}
   	return 0;
}

/**
 * Vypis obsahu zasobnika.
 */
void print_stack(struct stack* stack) { //vypis obsah stacku
	int idx; //inkrementacna premenna cyklu
	printf(">"); //vypis znak, za ktory vypiseme obsah zasobnika
	for ( idx = 0; idx < stack->size; idx++){
		printf(" %f ", stack->array[idx]);
	}
	printf("\n");
}

/**
 * Cela polska kalkulacka.
 */
void polish_calculator() {
	struct stack *stack = create_stack();
   	char buffer[256]; //buffer na nacitavanie premennych
   	float a; //prve cislo
	float b; //druhe cislo
  	float res; //vysledok operacie
   	while (1){	//bezi stale
		scanf("%s",buffer); //nacitanie znaku
        	if(isdigit(buffer[0])){  // Kontrola  ci je validne cislo 
			push_stack_value(stack,atof(buffer));
	  		print_stack(stack);
		}else{
            		a  = pop_stack_value(stack);	//vloz do stacku
            		b  = pop_stack_value(stack);
		if (buffer[0] == '+'){
                  	res = b + a;
                  	push_stack_value(stack, res);
        	}else  if (buffer[0] == '-'){
                  	res = b - a;
                  	push_stack_value(stack, res);
        	}else  if (buffer[0] == '*'){
                  	res = b * a;
                  	push_stack_value(stack, res);
        	}else  if (buffer[0] == '/'){
                  	res = b / a;
                  	push_stack_value(stack, res);
        	}else{
                  	printf("Neplatny znak!");
                }
	print_stack(stack);	//vypis aktualneho stacku
		}
	}
  delete_stack(stack); //uvolni pamat

}

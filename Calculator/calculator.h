#ifndef CALCULATOR_H
#define CALCULATOR_H

#define STACK_SIZE 100

struct stack {
    float array[STACK_SIZE];
    int size;
};

struct stack* create_stack();

void delete_stack(struct stack* stack);

void push_stack_value(struct stack* stack,float value);

float pop_stack_value(struct stack* stack);

void print_stack(struct stack* stack);

void polish_calculator();

#endif // CALCULATOR_H

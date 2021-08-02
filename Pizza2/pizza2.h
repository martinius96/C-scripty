#ifndef PIZZA2_H
#define PIZZA2_H

#define LINE_SIZE 100
#define LIST_SIZE 100

struct pizza {
	float prize;
    char name[LINE_SIZE];
};

int read_line(char* line, int size);
int read_pizza(struct pizza* item);
int compare_pizza (const void * a, const void * b);
void sort_pizza(struct pizza* list,int size);
int read_pizza_list(struct pizza* list, int size);
void print_pizza_list(struct pizza* list, int size);

#endif // PIZZA2_H

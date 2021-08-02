#include <stdio.h>
#include <string.h>
#include "pizza2.h"

/**
 * Nacita jeden riadok z klavesnice vratane konca riadka.
 *
 * @arg line  Pole kam sa ma ulozit vysledok
 * @arg size  velkost pola s vysleddkom.
 * @return Funkcia vrati EOF ak nastal koniec vstupu  vstupu alebo pocet nacitanych znakov.
 */
int read_line(char* line, int size) {
	int idx;
 	int c;
	for(idx=0; idx<size-1; idx++){
		c =getchar();
                line[idx] = c;
		line[idx+1] = 0;
                if(c==EOF){
                	line[idx] = 0; //ukonc retazec
                	printf("Koniec vstupu!\n");
                	return -1; //ukonc
		}
		if(c=='\n'){
                   	line[idx+1] = 0;
                  	return idx+1;
		}
	}
	line[idx+1] = 0;
        return 0;
}


/**
 * Naciata informacie o jednej pizzi z klavesnice.
 * Prvy riadok je nazov pizze ako retazec. Ak je prevy riadok prazdny, zaznam o pizzi je neplatny.
 * Druhy riadok je cena pizze akocislo s desatinnou bodkou. 
 *
 * Pozor - spravanie funkcie nie je definovane v pripade, ze pouzivatel zada neocakavany vstyup, napr.
 * pismena namiesto cisla.
 *
 * @arg item smernik kam sa ma nacitat info o pizzi
 * @return V pripade, ze pizza nebola nacitana uspesne, funkcia vrati nulu. Inak vrati jednotku.
 *
 */
int read_pizza(struct pizza* item){
	int res = read_line(item->name,LINE_SIZE);
	if (res == EOF || strlen(item->name) == 0){
    		return 0;
    	}
    	char buffer[LINE_SIZE];
    	res = read_line(buffer,LINE_SIZE);
    	if (res == EOF){
        	return 0;
    	}
    	res = sscanf(buffer,"%f",&item->prize); //desatinne cislo - float - cena pizze
    	if (res != 1){
        	return 0;
    	}
	return 1;
}

/**
 * Nacita jedalny listok zo suboru. Zaznamy o jedlach su v textovom formate ulozene za sebou.
 * Zoznam je ukonceny neplatnou pizzou }napr. prazdny riadok.|
 *
 * @arg pole do ktoreho sa ma naxitat
 * @arg size velkost pola
 * @return pocet nacitanych poloziek.
 *
 */
int read_pizza_list(struct pizza* list, int size){
int i;
for(i=0; i<size; i++){
		int r = read_pizza(&list[i]);
		if(r==0){
			return i;
		}
}
 return size;
}

/**
 * Vypise jedalny listok na obrazovku. Vypis by mal byt v takom formate, aby sa dal nacitat pomocou funkcie
 * read_pizza_list().
 *
 */
void print_pizza_list(struct pizza* list, int size){
	int i;
	printf("Zotriedeny zoznam pizz:\n");
	for (i = 0; i < size; i++) {
  		printf("Nazov pizze: %s", list[i].name);
    		printf("Cena: %f\n", list[i].prize);
   	}
}
/**
 * Funkcia na porovnanie dvoch ceny dvoch pizz.
 *
 * @arg smernik na prvu pizzu
 * @arg smernik na druhu pizzu
 * @return nula ak su pizze rovnake. Kladnu hodnotu aj je prva pizza drahsia. Zapornu inak.
 */
int compare_pizza (const void * prvapizza, const void * druhapizza) { //povonanie cien pizz
	struct pizza * prvapizzax = (struct pizza*)  prvapizza;
	struct pizza * druhapizzax = (struct pizza*) druhapizza;
	return (prvapizzax->prize - druhapizzax->prize);
}

/**
 * Triedenie pola pizz, podla porovnavacej funkcie compare_pizza
 *
 */
void sort_pizza(struct pizza* list,int size) { //triedenie
	qsort (list, size, sizeof(struct pizza), compare_pizza);
}

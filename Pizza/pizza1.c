#include <stdio.h>
#include "pizza1.h"
#include <string.h>
//PREKLAD: gcc -std=c99 pizza1.c - pre for prvotna deklaracia i ako parameter
//PREKLAD s make: i deklarovat pred sluckou
//Vyhotovil: Martin Chlebovec
/**
 * Nacita jeden riadok z klavesnice vratane konca riadka.
 *
 * @arg line  Pole kam sa ma ulozit vysledok
 * @arg size  velkost pola s vysleddkom.
 * @return Funkcia vrati EOF ak nastal koniec vstupu  vstupu alebo pocet nacitanych znakov.
 */
int read_line(char* line, int size) {
        printf("Zadajte retazec:");
	int idx; //index slucky, interuje sa
	int c; //nacitavany znak
	for(idx=0; idx<size-1; idx++){
                c =getchar();
                line[idx] = c;
		line[idx+1] = 0;
                if(c==EOF){
                line[idx] = 0; //ukonc retazec
                printf("Koniec vstupu!");
                return -1; //ukonc
	}
	line[idx] = c;
	if(c=='\n'){
        	line[idx+1] = 0;
                return idx+1;
	}
	}
	line[idx+1] = 0;
        return idx;
}

/**
 * Zistenie najdlhsieho retazca z pola smernikov
 * @arg Dvojrozmerne pole s retazcami. Velkost pola je LINESIZE x LISTSIZE
 * @arg velkost pola - pocet retazcov. Dvojrozmerne pole nemusi byt plne obsadene retazcami. Aktualny pocet retazcov je v premennej size.
 * @return index najldhsieho retazca v poli. Navratova hodnota by mala byt mensia ako size.
 */
int max_len(char list[][LISTSIZE],int size){
    	int max_len = 0; //dlzka retazca
    	int max_index = 0; //index jednotlivych znakov
    	int j = 0; //riadkova premenna
	int idx;
	for (idx = 0; idx < size; ++idx){
    		if (strlen(list[j]) < strlen(list[idx])){
			max_index = idx;
			max_len = strlen(list[idx]);
            		j++;
        	}
    	}
	return max_index;
}




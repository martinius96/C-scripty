/******************************************************************************
MARTIN CHLEBOVEC
TUKE, FEI,KEMT
POČÍTAČOVÉ SIETE
DÚ-14 - Zápočtové zadanie
IMPLEMENTACIA PERIODICKEJ KONVOLUCIE S VYUZITIM NTT
Číslo študenta: 9
Priradené vektory:
a[] = {0, 1, 1, 2, 1, 1, 2, 3};
b[] = {1, 2, 2, 3, 3, 2, 1, 2};
BIKS - Bezpečnosť informačných a komunikačných systémov
12. Dec. 2020
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include "ntt.h"      //obsahuje deklaracie funkcii pre vypocet
#include "gf.h"      // obsahuje makra s hodnotami omega, NTT SIZE, modulo atd..

int main(int argc, char* argv[]) {
//zaciatok merania casu
clock_t t; 
t = clock(); 
// POUZITE PRIDELENE HODNOTY VEKTOROV A a B. 
//a = {0,1,1,2,1,1,2,3}
//b = {1,2,2,3,3,2,1,2}
//C. STUDENTA: 9
ff a[NTT_SIZE] = {0,1,1,2,1,1,2,3};
ff b[NTT_SIZE] = {1,2,2,3,3,2,1,2};
ff A[NTT_SIZE], B[NTT_SIZE], C[NTT_SIZE], c[NTT_SIZE];
int k;

// incicializacia mocnin OMEGA^k, ktore sa ulozia do tabulky pre vypocet priamej transformacie NTT 
    if(ntt_table_init( OMEGA, NTT_SIZE, DIRECT )) {    
        fprintf(stderr, "Table Init Error\n");
        goto fail;
    }

// a podobne pre vypocet inverznej transformacie NTT^-1 
   if(ntt_table_init( INV_OMEGA, NTT_SIZE, INVERSE )) { 
        fprintf(stderr, "Inverse Table Init Error\n");
        goto fail;
    }

    // vypocet pomocou rychleho "FFT-like" vypoctu
   ntt(a, A, NTT_SIZE, DIRECT);
   ntt(b, B, NTT_SIZE, DIRECT);

   for(k=0; k<NTT_SIZE; k++)
   C[k] = ff_mul(A[k], B[k]);
   ntt(C, c, NTT_SIZE, INVERSE);
   for(k=0; k<NTT_SIZE; k++)
   printf("C_%d = %d\n", k, c[k]);    
    //Rozdiel meraneho casu
     t = clock() - t; 
     double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("Program sa vykonal za: %f sekund \n", time_taken); 
   return 0;
   
 //ODSTRANENE SLOW DFT VYPOCTY, TEST FUNKCIE, VYPISY 
fail:
    printf("failed test\n");
    return 1;
}





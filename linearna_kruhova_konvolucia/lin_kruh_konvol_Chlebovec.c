/******************************************************************************
MARTIN CHLEBOVEC
TUKE, FEI,KEMT
POČÍTAČOVÉ SIETE
DÚ-14 - Zápočtové zadanie
IMPLEMENTACIA LINEARNEJ A KRUHOVEJ KONVOLUCIE NA POSTUPNOSTI
Číslo študenta: 9
Priradené vektory:
a[] = {0, 1, 1, 2, 1, 1, 2, 3};
b[] = {1, 2, 2, 3, 3, 2, 1, 2};
BIKS - Bezpečnosť informačných a komunikačných systémov
13. Dec. 2020
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//#define SUCET //DIREKTIVA

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
#include <math.h> //pre funkciu pow() pre umocnenie
//int a[] = {1,2,3,4};
//int b[] = {5,6,7,8};

int a[] = {0, 1, 1, 2, 1, 1, 2, 3};
int b[] = {1, 2, 2, 3, 3, 2, 1, 2};
size_t N = sizeof(a)/sizeof(a[0]);
unsigned long c[16]; 

int modulo = 337;
int index_array = 0;
unsigned long* convolve(int h[], int x[], int lenH, int lenX, int* lenY)
{
  int nconv = lenH+lenX-1;
  (*lenY) = nconv;
  index_array = nconv-1;
//  printf("%d", nconv);
  int i,j,h_start,x_start,x_end;

  unsigned long *y = (unsigned long*) calloc(nconv, sizeof(unsigned long));

  for (i=0; i<nconv; i++)
  {
    x_start = MAX(0,i-lenH+1);
    x_end   = MIN(i+1,lenX);
    h_start = MIN(i,lenH-1);
    for(j=x_start; j<x_end; j++)
    {
      y[i] += h[h_start--]*x[j];
    }
  }
  return y;
}

void reverse(unsigned long arr[], int n);
int main(int argc, char *argv[])
{
    clock_t t; 
    t = clock(); 
  int lenY;
  unsigned long *y = convolve(a,b,(int)N,(int)N,&lenY);
  unsigned long sum = 0;
  #ifdef SUCET
  for(int i=0;i<lenY;i++) {
    y[i] = y[i]*(unsigned long)(pow(10, index_array));  
    sum +=y[i];
    index_array--;
    printf("%lu\n",y[i]);
  }
   printf("Sucet linearnej konvolucie: %lu\n", sum); 
   #endif
    #ifndef SUCET
  for(int i=0;i<lenY;i++) {
    index_array--;
    printf("%lu\n",y[i]);
  }
      int loop;
  printf("Postupnost: "); 
   for(loop = 0; loop < ((2*N)-1); loop++)
      printf("%lu ", y[loop]);
      printf("\n"); 
reverse(y, ((2*N)-1));
      printf("Otocena postupnost: "); 
   for(loop = 0; loop < ((2*N)-1); loop++)
      printf("%lu ", c[loop]);
      printf("\n"); 
  free(y);
  int n = sizeof(c)/sizeof(c[0]);
       c[15] = 0;
unsigned long cc[8]; 
 for(loop = 0; loop <= 7; loop++){
     cc[loop] =  (c[loop]+c[(loop+8)]) % modulo;
      printf("cc%d = %lu ",loop, cc[loop]);
      printf("\n"); 
 }
    #endif
   t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("Program sa vykonal za: %f sekund \n", time_taken); 
  return 0;
}

void reverse(unsigned long arr[], int n)
{
 
    for (int i = 0; i < n; i++) {
        c[n - 1 - i] = arr[i];
    }
 
    for (int i = 0; i < n; i++) {
        arr[i] = c[i];
    }
}

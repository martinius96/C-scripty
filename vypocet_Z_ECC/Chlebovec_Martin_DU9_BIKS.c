/******************************************************************************
MARTIN CHLEBOVEC
TUKE, FEI,KEMT
POČÍTAČOVÉ SIETE
DÚ-9 - Zápočtové zadanie
IMPLEMENTACIA Z = k*P, kde k=19, P[17,20]

Číslo študenta: 9
Priradené vektory:
x = 17
y = 20
z = 19

BIKS - Bezpečnosť informačných a komunikačných systémov
8. Nov. 2020
Revizia: 15. Nov. 2020 - oprava vzorca pre kongruenciu lavej strany
*******************************************************************************/
#include <stdio.h>
#include <math.h> //pre funkciu pow() pre umocnenie

//vstupne vektory
int xp = 17;
int yp = 20;
const int k = 19;

//kˆ(-1)
int inverzny_prvok;
//Prvky na Elip. krivke pri spocitavani parametrov P, Q
int s;
int xr;
int yr;
int xq;
int yq;

//PARAMETRE ELIPTICKEJ KRIVKY
//E_23(a,b)
const int a = 1;
const int b = 1;
const int E = 23;

//DEKLARACIE FUNKCII

int modInverse(int a, int m); //funkcia pre vypocet inverzie
void overenie_kongruencie(int num_xr, int num_yr, int mod_num ); //overenie kongruencie EC metodou

//VZŤAHY PRE P=Q
int vypocet_s_equal(int num_x, int num_a, int num_inv, int mod_num); //vypocet s
int vypocet_xr_equal(int num_x, int num_s, int mod_num); //vypocet xr

// VZŤAH rovnaky aj pre P≠Q
int vypocet_yr_equal(int num_s, int num_xp, int num_xr, int num_yp, int mod_num); //vypocet yr

//VZŤAHY PRE P≠Q
int vypocet_s_NOT_equal(int num_yq, int num_yp, int num_inv, int mod_num); //vypocet s
int vypocet_xr_NOT_equal(int num_xq, int num_xp, int s_num, int mod_num); //vypocet xr

//HODNOTY PRE DOPOCITANIE k = 19,t.j. P16+ P2 + P1 = P16+P3
int P1x = 17; //hodnoty zadefinovane pre P[x,y]
int P1y = 20;

int P2x=0;
int P2y=0;

int P3x=0;
int P3y=0;

int P16x=0;
int P16y=0;
int i = 1;
int multiply = 1; //pravidlo pre vypis indexov P --> mocninovo / staticky
int main()
{   
    printf("Vytvoril: MARTIN CHLEBOVEC - BIKS\n");
    printf("DU c.9\n\n");
    printf("Rozklad k=%d, na mocninove nasobky cisla 2\n", k);
    int mocnina = 4; //najvyssia mocnina cisla 2, mozno pouzit vyssie
    while(mocnina>=0){ //Rozklad 
        if((int)pow(2,mocnina)<=k){
         printf("2ˆ%d = %d\n", mocnina, (int)pow(2,mocnina));   
        }
        mocnina--;
    }
    printf("\n");
    printf("P[%d, %d], E_%d(%d,%d)\n", xp, yp, E, a, b);
    while(i<=4){ //vykonavame pre vypocet 2P, 4P, 8P, 16P
        printf("2*yp=%d\n", (2*yp)); //Vypis 2*yp
        printf("Inv. prvok(%d, %d) = %d\n", (2*yp), E, modInverse((2*yp), E)); //Vypis vypoctu kˆ(-1) --> inv. prvku
        printf("s = %d\n", vypocet_s_equal(xp, a, inverzny_prvok, E)); //Vypis vypoctu s pre P=Q
        printf("xr = %d\n", vypocet_xr_equal(xp, s, E)); //Vypis vypoctu xr  pre P=Q
        printf("yr = %d\n", vypocet_yr_equal(s, xp, xr, yp, E)); //Vypis vypoctu yr  pre P=Q a P≠Q
        overenie_kongruencie(xr, yr, E); //Vypis overenia kongruencie
        i++; //inkrement cyklu
    }
   //DEBUG --> Z testovania
   /*
   printf("P1x = %d\n", P1x); 
   printf("P1y = %d\n", P1y); 
   printf("P2x = %d\n", P2x); 
   printf("P2y = %d\n", P2y); 
   printf("P16x = %d\n", P16x); 
   printf("P16y = %d\n", P16y); 
   */
   
   //P3
   printf("\n\n2P+1P\n");
   printf("3P[?, ?]\n");
   int result = P2x-P1x;
   if(result<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        result = result+E;
    }
    //2P = P
    //P  = Q
    printf("Inv. prvok(%d, %d) = %d\n", result, E, modInverse(result, E)); //Vypis vypoctu kˆ(-1) --> inv. prvku
    printf("s = %d\n", vypocet_s_NOT_equal(P2y, P1y, inverzny_prvok, E)); //Vypis vypoctu s pre P≠Q
    printf("xr = %d\n", vypocet_xr_NOT_equal(P2x, P1x, s, E)); //Vypis vypoctu xr  pre P≠Q
    printf("yr = %d\n", vypocet_yr_equal(s, xp, xr, yp, E)); //Vypis vypoctu yr  pre P≠Q a P=Q
    multiply = 0; //staticky vypis indexu P
    i = 3; //index P
    overenie_kongruencie(xr, yr, E); //Vypis overenia kongruencie
    P3x=xp;
    P3y=yp;

    //P19
   printf("\n\n16P+3P\n");
   printf("19P[?, ?]\n");
   result = P16x-P3x;
   if(result<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        result = result+E;
    }
    //2P = P
    //P  = Q
    printf("Inv. prvok(%d, %d) = %d\n", result, E, modInverse(result, E)); //Vypis vypoctu kˆ(-1) --> inv. prvku
    printf("s = %d\n", vypocet_s_NOT_equal(P16y, P3y, inverzny_prvok, E)); //Vypis vypoctu s pre P≠Q
    printf("xr = %d\n", vypocet_xr_NOT_equal(P16x, P3x, s, E)); //Vypis vypoctu xr  pre P≠Q
    printf("yr = %d\n", vypocet_yr_equal(s, xp, xr, yp, E)); //Vypis vypoctu yr  pre P≠Q a P=Q
    i = 19; //index P
    overenie_kongruencie(xr, yr, E); //Vypis overenia kongruencie
    printf("Z = 19P(%d, %d)\n", xp,yp);
    return 0;
}

//funkcia pre najdenie inverzneho prvku modulo m, multiplikativna inverzia
int modInverse(int a, int m) 
{ 
    a = a % m; 
    for (int x = 1; x < m; x++) 
        if ((a * x) % m == 1){ 
         inverzny_prvok = x;
            return x; 
        }
} 

void overenie_kongruencie(int num_xr, int num_yr, int mod_num ) //EC overenie kongruencie
{ 
    int vypocet_x = (int)(pow(num_xr, 3)+num_xr+1) % mod_num;
    int vypocet_y = (int)(pow(num_yr, 2)) % mod_num; //OPRAVA --> FIX NESPRAVNY VZOREC
    if(vypocet_x<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        vypocet_x = vypocet_x+mod_num;
    }
    if(vypocet_y<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        vypocet_y = vypocet_y+mod_num;
    }
    if(vypocet_x==vypocet_y){
        printf("EC kontrola (%d, %d), OK, SU KONGRUENTNE, TEST PASSED\n", num_xr,num_yr);
        xp = num_xr;
        yp = num_yr;
        if(i==1){
            P2x=xp;
            P2y=yp;
        }
        
        if(i==4){
            P16x=xp;
            P16y=yp;
        }
        printf("\n\n");
        if(multiply==1){
        printf("%dP[%d, %d]\n", (int)(pow(2, i)), xp, yp);
        }else{
         printf("%dP[%d, %d]\n", i, xp, yp);   
        }
    }else{
        printf("EC kontrola (%d, %d), PROBLEM, NIE SU KONGRUENTNE, TEST FAILED\n", num_xr,num_yr); 
        while(1); //PROBLEM, ZASTAV DALSIE PROGRAMU
        
    }
} 

//VZŤAHY PRE P=Q
int vypocet_s_equal(int num_x, int num_a, int num_inv, int mod_num) //VYPOCET s PRE P=Q
{ 
    s = (int)((3*pow(num_x, 2)+num_a)*num_inv) % mod_num;
    if(s<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        s = s+mod_num;
    }
    return s;
} 

int vypocet_xr_equal(int num_x, int num_s, int mod_num) //VYPOCET xr PRE P=Q
{ 
    xr = (int)(pow(num_s, 2)-2*num_x) % mod_num;
    if(xr<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        xr = xr+mod_num;
    }
    return xr;
} 

int vypocet_yr_equal(int num_s, int num_xp, int num_xr, int num_yp, int mod_num) //VYPOCET yr PRE P=Q
{ 
    yr = (int)(num_s*(num_xp-num_xr)-num_yp) % mod_num;
    if(yr<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        yr = yr+mod_num;
    }
    return yr;
} 

//VZŤAHY PRE P≠Q
int vypocet_s_NOT_equal(int num_yq, int num_yp, int num_inv, int mod_num) //VYPOCET s PRE P≠Q
{ 
    s = (int)((num_yq-num_yp)*num_inv) % mod_num;
    if(s<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        s = s+mod_num;
    }
    return s;
} 

int vypocet_xr_NOT_equal(int num_xq, int num_xp, int s_num, int mod_num) //VYPOCET xr PRE P≠Q
{ 
    xr = (int)(pow(s_num, 2)-num_xp-num_xq) % mod_num;
    if(xr<0){ //prevedenie cisla do kladnej reprezentacie modulo m
        
        xr = xr+mod_num;
    }
    return xr;
} 
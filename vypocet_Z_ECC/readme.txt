------------MARTIN CHLEBOVEC------------
------------DU c. 9---------------------

Cislo studenta: 9
Vstupne vektory: x = 17 y = 20 z = 19

Pri realizacii zadania domacej ulohy c.9 som vyuzil programovu implementaciu
v jazyku C. Zapisal som predpisane funkcie pre vypocet parametrov (xr, yr, s)
pre variant vypoctu P=Q a P≠Q do C jazyka ako funkcie, ktore si volam.

Na zaklade poznatkov z rucneho vypoctu tejto DU som vedel, ake nasobky
jednotlivych P su potrebne. Z toho dovodu su iste casti zdrojoveho kodu
staticke (ktore som nevedel efektivnejšie zapisat), 
ine dynamicke a zapisane univerzalne.

Vypocty
Pre P=Q:
2P, 4P, 8P, 16P

Pre P≠Q:
3P, 19P

Nakolko som nevedel v jazyku C implementovat spatny chod Euklidovho
algoritmu, ktory som pouzival v papierovej DU a z ktorej som si vyjadril
inverzny prvok, pouzil som C funkciu pre multiplikativnu inverziu zo zdroja:
https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
GCD (Euklidov algoritmus som teda vo vysledku v prog. implementacii nepouzil)

Pri rieseni programu a jeho vystupu som zaroven pouzival papierovu verziu
pre kontrolu riesenia a spravnost vysledkov. Riesenie hodnot x a y pre kazdy 
parameter P je overeny EC metodou porovnanim vzajomnej kongruencie 
oboch prvkov.

Funkcnost programu:
V cykle while sa vypocitaju a vypisu hodnoty 2P, 4P, 8P, 16P pre P=Q.
Program vypisuje aj (inverz. prvok, s, xr, yr, kongruenciu pri overeni)
t.j. vsetky medzivysledky.

Nasledne program vypocita hodnotu pre 3P a 16P a nasledne sa suctom vypocita
19P, ktore reprezentuje vysledok Z = k*P = 19P[13, 16]. 

Preklad programu som realizoval bez Makefilu len prikazom:
gcc -std=c99 -o main Chlebovec_Martin_DU9_BIKS.c -lm (spustane na Cent OS Linux)

Program je funkcny a odpoveda hodnotam dosiahnutym v papierovej DU5. 
Zdrojovy kod je komentovany pre lepsiu orientaciu.

V programe som vykonaval prepocty vsetkych medzivysledkov modulo m na kladne.
V prilozenom .pdf dokumente je viditelny vystup programu 
do konzolovej aplikacie s vypisom jednotlivych medzivysledkov a vysledkov.
Programova implementacia ma cca 240 riadkov.

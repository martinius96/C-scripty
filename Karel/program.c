#include <karel.h>             // nalinkovanie prislusnej kniznice, ktorej definicie budeme v programe vyuzivat.
#define SPEED 100              // definicia rychlosti pohybu
void Switcher(void);
void turnRight(void);
void moveBack2x(void);
void moveBack(void);
void sub(void);
void rewriteFirstNum(void);
void minusSecondNum(void);
// DEFINUJEME FUNKCIE
void moveBack2x(void)        // funkcia s dvojitym pohybom dozadu a obratom, vyuzivana pri presune z horneho cisla pri prepise
{
loop(2)
{
turnLeft();
}
loop(2)
{
movek();
}
loop(2)
{
turnLeft();
}
}
void moveBack(void)     // funkcia s pohybom dozadu a obratom, vyuzivana pri presune o jedno cislo vyssie pri samotnom odcitani cisla
{
loop(2)
{
turnLeft();
}
movek();
loop(2)
{
turnLeft();
}
}
void Switcher(void)    // funkcia Switcher pre switchovanie medzi 2 funkciami, na druhu funkciu prepne az po korektnom vykonani prvej.
{
moveBack2x();
rewriteFirstNum();
movek();
minusSecondNum();
}
void rewriteFirstNum(void)  // funkcia prepisu prveho cisla v stlpci, funkcia vyuziva dvojnasobny pohyb dozadu
{
pickBeeper();
if ( beepersPresent() )// ak je na pozicii stale beeper, tak zdvihaj
{
rewriteFirstNum();
}
putBeeper(); // nakoniec na prazdne miesto poloz beeper
loop(2)
{
movek();
}
putBeeper(); //poloz beeper pod mensenca
moveBack2x();
}
void minusSecondNum(void)    //funkcia odcitania druheho cisla v stlpci s vyuzitim jedneho posunu dozadu
{
pickBeeper();
if ( beepersPresent() ) //zdvihaj beeper, ak je stale na pozicii
{
minusSecondNum();
}
putBeeper();
movek();
pickBeeper(); //zober beeper od mensenca, odcitavam
moveBack();
}
void sub(void) // hlavna funkcia, ktora plni odcitanie, obsahuje podfunkciu Switcher, ktora obsahuje dalsie 2 podfunkcie pre prepis a odcitanie cisla
{
movek();
turnRight();
loop(2)
{
movek();
}
Switcher();    //Switcher spusta prepis i odcitanie cisel vramci funkcii
loop(2)
{
turnRight();
}
movek();
turnRight();
}
void turnRight(void)    // funkcia pre otocenie doprava
{
loop(3)
{
turnLeft();
}
}
int main(){ //hlavna funkcia main, v ktorej sa vykonava samotny kod programu
turnOn("world.kw"); // spustenie sveta robota
setStepDelay(SPEED);    //rychlost krokov definovana SPEED-om --> definovany hore
loop(3)
{        //slucka 3x funkcia sub pre kompletne odcitanie troch stlpcov za sebou
sub();
}
movek();        //zaciatok pohybu do vyslednej  polohy robota
turnRight();
loop(2){movek();}
turnLeft();      //koniec pohybu do vyslednej polohy robota
turnOff();    //ukoncenie programu
return 0;
}

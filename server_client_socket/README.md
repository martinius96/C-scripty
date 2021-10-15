* Vytvorte 2 programy
* TCP/IP server – syntax: server <port>
* Program server otvorí na porte <port> listener
* server čaká na správy
* po prijatí je vypísaná na stdout – štandardný výstup. 
* Vypíše status na štandardný výstup o počte prijatých bajtov, uzavrie port a skončí.

* TCP/IP klient – syntax: client <ip> <port>
* Program klient po spustení načítava zo štandardného vstupu
* textové dáta (%s) po riadkoch (napr. cez fscanf alebo fgets).
* Potom sa pripojí na <ip> <port> servera definovaný v
* príkazovom riadku a správu pošle na server a spojenie ukončí.

* Pozn.
* Ošetrite chyby pri otváraní TCP spojení a portov.
* Po presmerovaní textového súboru do stdin program klient je možné
* poslať obsah prvého riadku textového súboru. Podobne na server po
* presmerovaní výstupu z stdout do súboru sa obsah zapíše na strane
* servera.

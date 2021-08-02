#include <stdio.h>
#include "pizza1.c"
#include <string.h>

int main(int argc, char** argv[]){
 
       char line[LINESIZE];
//pouzitie funkcie read_line
        int res = read_line(line, LINESIZE);
//------DEBUG - PRINT
        printf("Res sa rovna:");
        printf("%d\n",res);
        printf("Cele pole:");
	int idx;
	for(idx = 0; idx <= res; idx++) {
                printf("%d ", line[idx]);
        }
        printf("\n");
//------END-DEBUG-PRINT
//---------------------------------
//---------------------------------
//DEBUG PRINT - DRUHA CAST - 2D pole
        printf("DRUHA CAST PROGRAMU\n");
        char jedalny_listok[LINESIZE][LISTSIZE];
	int i;
	for (i = 0; i <2 ; i++){
  		int res2 = read_line(jedalny_listok[i],LINESIZE);
  	if (res == EOF){
    		break;
  	}
	}
	if (max_len(jedalny_listok, 100) >= 0){
 		printf("Najdlhsi retazec je: %s\n", jedalny_listok[max_len(jedalny_listok,i)] );
	}
//END DEBUG PRINT - DRUHA CAST
	return 0;
}

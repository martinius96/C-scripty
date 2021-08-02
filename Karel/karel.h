/*
 * karel.h
 */

#ifndef KAREL_H_
#define KAREL_H_

// loop() macro to replace for()
#define loop(COUNT) for( int __loop_counter = 0; __loop_counter < COUNT; __loop_counter++ )

/*typedef enum BOOLEAN{
        TRUE = 1,
        FALSE = 0
} Boolean;*/
#define TRUE 1
#define FALSE 0

#define MAX_WIDTH       20
#define MAX_HEIGHT      20

typedef enum ERROR{
    NO_PROBLEM = 0,
    UNKNOWN_BLOCK,
    TOO_BIG_WORLD,
    FILE_NOT_FOUND,
    CANT_MOVE,
    NO_BEEPER_IN_BAG,
    NO_BEEPER_AT_CORNER,
    KAREL_IS_OFF
} Error;

typedef enum DIRECTION{
        EAST = 0,
        NORTH = 90,
        WEST = 180,
        SOUTH = 270
} Direction;

typedef enum BLOCK {
        CLEAR,
        WALL = 9
} Block;

void movek();
void turnLeft();
void turnOff();
void putBeeper();
void pickBeeper();
int beepersPresent();
int noBeepersPresent();
int beepersInBag();
int noBeepersInBag();

int frontIsClear();
int frontIsBlocked();
int leftIsClear();
int leftIsBlocked();
int rightIsClear();
int rightIsBlocked();


void draw();
void redraw();

int facingNorth();
int notFacingNorth();
int facingEast();
int notFacingEast();
int facingWest();
int notFacingWest();
int facingSouth();
int notFacingSouth();

int turnOn( char* path );

void setStepDelay(int);

#endif /* KAREL_H_ */

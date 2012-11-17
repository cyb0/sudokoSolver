// SudokoGrid.h

#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUES (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUES * NUM_VALUES) // max values: 81
#define MAX_CELL (GRID_SIZE - 1) // the last cell: 80

#define TRUE 1
#define FALSE 0

typedef char value; // think of cell value instead of char type variable
typedef int cell;   // think of cell instead of the address of a memmory
typedef value sudokoGrid[GRID_SIZE]; // think of sudokoGrid instead of just an array

int hasSolution (sudokoGrid game);

// given a grid, replaces all cell values by the values in a file
// EMPTY_VALUE means blank, cell, digits are digist, all else is ignored
void readGame (sudokoGrid game);

// non-zero if it would be legal to set the specified digit
int isLegal (sudokoGrid game, cell location, value candidateDigit);

int isLegalBasic (sudokoGrid game, cell location, value candidateDigit);

// dispay a suduko game in a format which can be read by readers
void showGame (sudokoGrid game);

// display the initial state of the game grid
void showInitialGame (sudokoGrid game);

// sets the specified cell to the specified digit
// assumes cell and digit are in legal range
void setCell (sudokoGrid game, cell location, value digit);

// returns digit in specified cell, or EMPTY_VALUE
// assumes cell location is in legal range
value getCell (sudokoGrid game, cell location);

// sets the specified cell to be blank
// assumes cell location is in legal range
void clearCell (sudokoGrid game, cell location);

// returns 0 if game contains at lease on blank cell
int isFull (sudokoGrid game);

// returns the location of a blank cell, assumes ...
cell getEmptyCell (sudokoGrid game);

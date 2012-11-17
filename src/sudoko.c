/* This program is a project to write a function which will calculate the values
 * of cells in a given Sudoko game. 
 *
 * by Tsvetomir Totev <cybershade@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 * 
 */

#include <stdio.h>
#include "SudokoGrid.h"

typedef char value; // think of cell value instead of char type variable
typedef int cell;   // think of cell instead of the address of a memmory
typedef value sudokoGrid[GRID_SIZE]; // think of sudokoGrid instead of just an array

int main (int argc, const char * arg []) {

    printf ("Running...\n");
    // testSudukoGrid();

    //defines a name for a sudukoGrid
    sudokoGrid sample;


    // TODO: read the initial grid 
    readGame (sample);

    int a; 
    a = sizeof(sample);
    printf ("sizeof sample: %d \n", a);

    value l_value;
    cell location = 3;
    l_value = getCell(sample, location);

    printf("game location [3] is: %c \n", l_value);

    a = isFull(sample);
    
    printf("is the game full: %d\n 0 - not full; 1 - is full\n" , a);

    showInitialGame (sample);
    
    if (hasSolution (sample)) {
        showGame (sample);
    }
    return 0;
}

int hasSolution (sudokoGrid game) {
    int solved;
    cell candidateCell;
    value trialValue;

    if (isFull (game)) { 
        solved = TRUE;
    } else {
        candidateCell = getEmptyCell (game);
        trialValue = MIN_VALUE;
        solved = FALSE;

        while (!solved && (trialValue <= MAX_VALUE)) {
            if (isLegal (game, candidateCell, trialValue)) {
                setCell (game, candidateCell, trialValue);

                if (hasSolution (game)) {
                    solved = TRUE;
                } else {
                    clearCell (game, candidateCell);
                }   
             }   
            trialValue ++; 
        }   
    }   
    return solved;
}

void readGame (sudokoGrid game) {
    // should read a grid file and check if all position are corectly filled
    // with EMPTY_VALUE or digits between MIN_VALUE and MAX_VALUE
    // all else is ignored
    // then call showGame() to display the sudoko grid

    FILE *fp;
    fp = fopen("grid.txt", "r"); // grid values goes in grid.txt
    
    if ( fp == 0 ) {
        printf ("Could not read file\n");
    } 

    cell location; // loop control 
    value ch; // character from file

    // load the array with the values froom file
    for (location = 0;  ((ch = fgetc (fp)) != EOF) && location <= MAX_CELL; location++) {
        if (isLegalBasic(game, location, ch)) {
            setCell (game, location, ch);
        }
    }
    fclose(fp);
}

int isLegal (sudokoGrid game, cell location, value candidateDigit) {

    return FALSE;
}

int isLegalBasic (sudokoGrid game, cell location, value candidateDigit) {
    // basic data clarity check
    int isLegal;

    if (candidateDigit == EMPTY_VALUE || (candidateDigit >= MIN_VALUE && candidateDigit <= MAX_VALUE)) {
        isLegal = TRUE;
    } else {
        isLegal = FALSE;
    }
    return isLegal;
    
}

void showGame (sudokoGrid game) {

    printf("!!!END OF THE PROGRAM!!!\n");
}

void showInitialGame (sudokoGrid game) {
    // should read the file and print the game in suitable format 
    // new line on 9 element; spaces between elements

/*  FILE *fp;
    fp = fopen("grid.txt", "r");

    if (fp == 0) {
        printf ("Could not open file!\n");
    }
*/ 
    int i; // loop control 0/9 = 0 ;)

    for (i = 0; i <= MAX_CELL; i++) {

        if (i != 0 && ((i%9) == 0)) {
            printf ("\n");
        }
        printf ("%c ", game[i]);
    }
    printf ("\n");
}
 
void setCell (sudokoGrid game, cell location, value digit) {

    game[location] = digit;

}

value getCell (sudokoGrid game, cell location) {

    value ch;
    ch = game[location];
    return ch;

}

void clearCell (sudokoGrid game, cell location) {

    game[location] = EMPTY_VALUE;

}

int isFull (sudokoGrid game) {

    int i;
    int isFull;

    for (i = 0; i <= MAX_CELL; i++) {
        if ((game[i] == EMPTY_VALUE)) {
            isFull = FALSE;
            break;
        } else {
            isFull = TRUE;
        }
    }
    return isFull;
}

cell getEmptyCell (sudokoGrid game) {

    int i;
    cell location;

    for (i = 0; i <= MAX_CELL; i++) {
        if (game[i] == EMPTY_VALUE) {
           location = i;
           break;
        }
    }
    return location;
}


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
    readGame(sample);

    showGame (sample);

    if (hasSolution(sample)) {
        showGame(sample);
    }

    return 0;
}

int hasSolution (sudokoGrid game) {
    int solved;
    cell candidateCell;
    value trialValue;

    if (isFull(game) ) { 
        solved = TRUE;
    } else {
        candidateCell = getEmptyCell(game);
        trialValue = MIN_VALUE;
        solved = FALSE;

        while (!solved && (trialValue <= MAX_VALUE)) {
            if (isLegal(game, candidateCell, trialValue)) {
                setCell(game, candidateCell, trialValue);

                if (hasSolution(game)) {
                    solved = TRUE;
                } else {
                    clearCell(game, candidateCell);
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

    for (location = 0; location < 80; location++) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '.' || (ch >= MIN_VALUE && ch <= MAX_VALUE)) {
                setCell(game, location, ch);
            }
        }
    }

    fclose(fp);
}
int isLegal (sudokoGrid game, cell location, value candidateDigit) {
    // i should move the condition x == EMPTY_VALUE || ( x >= MIN_VALUE && x <= MIN_VALUE )
    // here

    return 0;
    
}

void showGame (sudokoGrid game) {
    printf ("showGame()\n");

    FILE *fp;
    fp = fopen("grid.txt", "r");

    if (fp == 0) {
        printf ("Could not open file!\n");
    }
    
    int i = 1; // control loop var

    value ch;

    while ((ch = fgetc(fp)) != EOF) {
        printf ("%c ", ch) ;

        if ( (i%9) == 0 ) {
            printf (" \n");
        }
        i++;
        
    }
    
}

void showInitialGame (sudokoGrid game, FILE *file) {
    // should read the file and print the game in suitable format 
    // new line on 9 element; spaces between elements
}

void setCell (sudokoGrid game, cell location, value digit) {

    game[location] = digit;
    
}

value getCell (sudokoGrid game, cell location) {

    return 0;
}

void clearCell (sudokoGrid game, cell location) {

}

int isFull (sudokoGrid game) {
    
    return 0;
}

cell getEmptyCell (sudokoGrid game) {

    return 0;
}


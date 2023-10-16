/*
EECS 348 Lab 5
Tatum Morris 
3062485
Description: This problem will ask the user for an integer, which is taken as a score. It will then produce the output of all the different scoring possibilites for the game. 
Date: 10/12/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Scores(int Score) {
    int TD_0, TD_1, TD_2, FG, SFT; 
    printf("Possible combinations of scoring plays: \n\n");
    for (TD_2 = 0; TD_2 <= Score/8; TD_2++) {
        for (TD_1 = 0; TD_1 <= (Score - (8*TD_2))/7; TD_1++) {
            for (TD_0 = 0; TD_0 <= (Score - (8*TD_2) - (7*TD_1))/6; TD_0++) {
                for (FG = 0; FG <= (Score - (8*TD_2) - (7*TD_1) - (6*TD_0))/3; FG++ ) {
                    for(SFT = 0; SFT <=(Score - (8*TD_2) - (7*TD_1) - (6*TD_0) - (3*FG))/2; SFT++) {
                        int scoreCombo = Score - (8*TD_2) - (7*TD_1) - (6*TD_0) - (3*FG) - (2*SFT);
                        if (scoreCombo == 0){
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety \n", TD_2, TD_1, TD_0, FG, SFT);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int stop = 0;
    int u_input; 
    do {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        
        scanf("%i", &u_input);
        
        if (u_input <= 1 && u_input >= 0){
            stop = 1;
            if (u_input == 0) {
                printf("Go KU!\n");
            }
        }
        else {
            printf("Invalid input. Please enter positive integer. \n");
        }
        if (stop == 0) {
            Scores(u_input);
        }
        
    } while(stop == 0);
    return 0;
}
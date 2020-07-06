//
//  main.c
//  CubeScrambler
//
//  Created by Rudaina Khalil on 7/6/20.
//  Copyright © 2020 Rudaina Khalil. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char * argv[]) {

    
    srand(time(NULL)); //for random seed generator
    
    char* moves = "RLFBUD"; //all possible moves of cube
    char* type = " '2"; //turn type
    
    int sequence = 25; //default
    printf("How many moves? If you want the default, input 0: ");
    scanf("%d", &sequence);
    
    if(sequence == 0){
        sequence = 25;
    }
    
    int move = 0; //these two will be used to increment pointers to the strings
    int mtype = 0;
    
    int previousMove;
    
    
    for (int i = 0; i<sequence;i++){
        move = rand()%6; //should provide a number from 0 to 5
        bool valid = false;
        while(i!=0 && valid == false){ //ensures no redundant moves
            if(previousMove != move){
                valid = true;
            } else {
                while (valid == false){
                    move = rand()%6;
                    if(previousMove == move){
                        valid = false;
                    } else {
                        valid = true;
                    }
                }
            }
        }
        mtype = rand()%3; //should provide a number from 0 to 2
        printf("%c",*(moves+move));
        if(mtype == 0){
        } else {
            printf("%c", *(type+mtype));
        }
        printf(" ");
        previousMove = move;
    }
    
    printf("\n");
    return 0;

}

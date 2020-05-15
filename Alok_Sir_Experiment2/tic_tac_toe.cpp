
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<bits/stdc++.h>
#include"tic_tac_toe.h"

using namespace std;

bool turn = true;
int count = 0 , place = 0;
bool win = false;
int pointer[42];
bool doub = false;

int my_pos[5][5];
int comp_pos[5][5];

int main(){
    int val;
    bool rule = true;
    board_init(M,N,K);
    matrix_init(matrix,M,N,sd);
    
    printf("Welcome To TIC TAC TOE MEGA\nInitializing...\n");
	for(int i=1;i<=6;i++){
		for(int j=1;j<=7;j++){
			matrix[i][j]=' ';	
		}
	}
	srand(time(0));
    printf("Completed\n\n");
	
	printf("Game Begins\n");
    int ch=0;
    int x,y;
    // Selecting Difficulty level
	printf("Select your difficulty level\n1. Easy\n2. Pro\n3. Impossible\n");
	printf("Enter Your choice: \n");
	scanf("%d", &ch);
	MAXDEPTH=4 + 2*ch;
	
    printf("Do you want to go first?\nPress 1 if yes\n0 otherwise\n\n");
	scanf("%d", &ch);
	if(ch){
		maximiser=s_p1;
		minimiser=s_cpu;
	}
	else{
		maximiser=s_cpu;
		minimiser=s_p1;
		Insert(M/2,N/2, maximiser);
	}
    // Game Loop
	while(true){
        printf("\nlets play\n");
		print_layout();
        if(wins(maximiser)){
			printf("I won, You lost!\n");
			break;
		}
		else if(nomovesleft()){
			printf("Boring\n");
			break;
		}
		
		
        else{
			    printf("\nYour turn\n\n");
			//while(true){
				scanf("%d,%d", &y,&x);
				if(matrix[y][x]!=' '){
				printf("You're dumb!\n");
                 // sorry sir for using it
                //	break;
				}
				
			//}
			printf("\nok");
            Insert(y,x, minimiser);
		}
		//print_arr(p1_win,sizeof(p1_win)); 
		//print_arr(cpu_win,sizeof(cpu_win));
        print_layout();
       if(wins(minimiser)){
			printf("GG\n");
			break;
		}
		else if(nomovesleft()){
			printf("Boring\n");
			break;
		}
		else{
			printf("My turn\n\n");1,
			findmove(y,x);
			Insert(y,x, maximiser);
		}
	}
	
    return 0;
}
	
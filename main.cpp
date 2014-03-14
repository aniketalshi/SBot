#include <iostream>
#include <stdio.h>
#include "board/board_util.h"
#include "test/test.h"

using namespace std;


int main() 
{  
    //test2();
    //bitboard_t GC = GROUP(GOLD) & (Bitboard[8][0] | Bitboard[9][0]);
    //cout << display_peices(GC, GOLD, DOG); 
     
    //bitboard_t b = 0x0024420C400800;
    //printf ("\n Orignal Board %p \t NEAR Positions %p\n", b, NEAR(b));    
    //cout << display_peices(GROUP(GOLD), GOLD,  RABBIT);
    
    //test3();
    //cout << display(GROUP(GOLD) | GROUP(SILVER));
    //cout << display(NOT_FROZEN(GOLD)); 
    //cout << display(ONE_STEP_MOVE(GOLD));
    //bitboard_t b = TWO_STEP_MOVE(GOLD, DOG);
    //cout << display(b); 
    //cout << display(WEAKER(SILVER, CAMEL)); 
   
    //test4();
    //cout << display(GROUP(GOLD) | GROUP(SILVER));
    //cout << display(TWO_STEP_MOVE(GOLD, DOG));
    
    test4();
    cout << endl << print_full_board();
    
    return 0;
}

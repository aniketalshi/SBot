#include <iostream>
#include <stdio.h>
#include "board/board_util.h"

using namespace std;

void test1() {
    /* init values for Bitboard array */
    
    Bitboard[0][0]  = 0x1;
    Bitboard[1][0]  = 0x2;
    Bitboard[2][0]  = 0x4;
    Bitboard[3][0]  = 0x8;
    Bitboard[4][0]  = 0x10;
    Bitboard[5][0]  = 0x20;
    Bitboard[6][0]  = 0x40;
    Bitboard[7][0]  = 0x80;
    Bitboard[8][0]  = 0x100;
    Bitboard[9][0]  = 0x200;
    Bitboard[10][0] = 0x400;
    Bitboard[11][0] = 0x800;
    Bitboard[12][0] = 0x1000;
    Bitboard[13][0] = 0x2000;
    Bitboard[14][0] = 0x4000;
    Bitboard[15][0] = 0x8000;

}


int main() 
{  
    test1();
    bitboard_t b = GROUP(GOLD);
    bitboard_t GC = GROUP(GOLD) & (Bitboard[8][0] | Bitboard[9][0]);
    //cout << display_peices(Bitboard[10][0], GOLD, DOG); 
    cout << display_peices(GC, GOLD, DOG); 
     
    //bitboard_t b = 0x0024420C400800;
    //printf ("\n Orignal Board %p \t NEAR Positions %p\n", b, NEAR(b));    
    //test1(); 
    //cout << display(Bitboard[0][3], 1);
    //cout << display(GROUP(0), RABBIT);
    return 0;
}

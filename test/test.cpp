#include "test.h"

void test2() {
    /* init values for Bitboard array */
    
    Bitboard[0][0]  = 0x1;     //rabbits
    Bitboard[1][0]  = 0x2;     //rabbits     
    Bitboard[2][0]  = 0x4;     //rabbits
    Bitboard[3][0]  = 0x8;     //rabbits
    Bitboard[4][0]  = 0x10;    //rabbits
    Bitboard[5][0]  = 0x20;    //rabbits
    Bitboard[6][0]  = 0x40;    //rabbits
    Bitboard[7][0]  = 0x80;    //rabbits
    Bitboard[8][0]  = 0x100;   //cat
    Bitboard[9][0]  = 0x200;   //cat
    Bitboard[10][0] = 0x400;   //dog
    Bitboard[11][0] = 0x800;   //dog
    Bitboard[12][0] = 0x1000;  //horse
    Bitboard[13][0] = 0x2000;  //horse
    Bitboard[14][0] = 0x4000;  //camel
    Bitboard[15][0] = 0x8000;  //elephant

    
    Bitboard[0][1]  = 0x1000000000000;     //rabbits
    Bitboard[1][1]  = 0x2000000000000;     //rabbits     
    Bitboard[2][1]  = 0x4000000000000;     //rabbits
    Bitboard[3][1]  = 0x8000000000000;     //rabbits
    Bitboard[4][1]  = 0x10000000000000;    //rabbits
    Bitboard[5][1]  = 0x20000000000000;    //rabbits
    Bitboard[6][1]  = 0x40000000000000;    //rabbits
    Bitboard[7][1]  = 0x80000000000000;    //rabbits
    Bitboard[8][1]  = 0x100000000000000;   //cat
    Bitboard[9][1]  = 0x200000000000000;   //cat
    Bitboard[10][1] = 0x400000000000000;   //dog
    Bitboard[11][1] = 0x800000000000000;   //dog
    Bitboard[12][1] = 0x1000000000000000;  //horse
    Bitboard[13][1] = 0x2000000000000000;  //horse
    Bitboard[14][1] = 0x4000000000000000;  //camel
    Bitboard[15][1] = 0x8000000000000000;  //elephant


}

void test3() {
    //frozen piece

    Bitboard[0][0] = 0x200;
    Bitboard[9][1] = 0x400;
  
    //frozen piece but with ally 
    
    Bitboard[10][0]  = 0x40000000;
    Bitboard[14][1]  = 0x20000000;
    Bitboard[13][0]  = 0x400000;
}

void test4() {
    
    Bitboard[12][0] = 0x80000;        //Gold Horse 1
    Bitboard[13][0] = 0x2000000000;   //Gold Horse 2

    Bitboard[0][1]  = 0x1000000000;   //Silver rabbit 1 which can be pulled by gold horse 2
    Bitboard[15][1] = 0x40000;       //Silver Elephant next to gold horse 1

}


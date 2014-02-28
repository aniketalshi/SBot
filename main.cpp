#include <iostream>
#include <stdio.h>
#include "board/board_util.h"

using namespace std;

int main() 
{
    bitboard_t b = 0x0024420C400800;
    printf ("\n Orignal Board %p \t NEAR Positions %p\n", b, NEAR(b));    
    
    cout << display(b, 1);
    cout << display(NEAR(b), 1);
    return 0;
}

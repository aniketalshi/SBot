#include "board_util.h"

using namespace std;

int map_rank_index (int rank) {

    if      (rank == 0) return 0;
    else if (rank == 1) return 8;
    else if (rank == 2) return 10;
    else if (rank == 3) return 12;
    else if (rank == 4) return 14;
    else if (rank == 5) return 15;

    return 0;
}

const bitboard_t COLUMN_H    = 1ULL | (1ULL << 8) | (1ULL << 16) | (1ULL << 24) |(1ULL << 32) | (1ULL << 40) | (1ULL << 48) | (1ULL << 56) ;
const bitboard_t COLUMN_A    = (1ULL << 7) | (1ULL << 15) | (1ULL << 23) | (1ULL << 31) | (1ULL << 39) | (1ULL << 47) | (1ULL << 55) | (1ULL << 63) ;
bitboard_t EMPTY             = 0xFFFFFFFF0000;

/* bitboard representation */
const char PieceArray[16][2] = { { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'R','r' },
                                 { 'C','c' },
                                 { 'C','c' },
                                 { 'D','d' },
                                 { 'D','d' },
                                 { 'H','h' },
                                 { 'H','h' },
                                 { 'M','m' },
                                 { 'E','e' }};

/*
 * Bitboard [0][0] - [15][0] - Gold Pieces bitboards
 * Bitboard [0][1] - [15][0] - Silver Pieces bitboards 
 */
bitboard_t Bitboard[16][2];


/******************************** Movement functions ***************************************/

bitboard_t MOVE_NORTH (bitboard_t b)       {return ((b) << 8);             }
bitboard_t MOVE_EAST  (bitboard_t b)       {return ((b & ~COLUMN_H) << 1); }
bitboard_t MOVE_WEST  (bitboard_t b)       {return ((b & ~COLUMN_A) >> 1); }
bitboard_t MOVE_SOUTH (bitboard_t b)       {return ((b) >> 8);             }
bitboard_t NEAR  (bitboard_t b)            {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}

/*GOLD RABBITS north move is illegal*/ 
bitboard_t GR_NEAR  (bitboard_t b)         {return ((MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}
/*SILVER RABBITS south move is illegal*/ 
bitboard_t SR_NEAR  (bitboard_t b)         {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)));}

/* Returns positions of all peices of same color */
bitboard_t GROUP (bool color) {
    bitboard_t b = 0x0;
    int i = 0;
    for (i = 0; i < 16; ++i) 
        b = b | Bitboard[i][color];
    
    return b;
}


/* Returns positions of peices of same color stronger than piece */
bitboard_t STRONGER (bool color, int piece) {
    bitboard_t retb = 0x0;
    int indx;
   
   /* rank is less than elephant */
    if (piece < R_COUNT - 2) {
        indx = map_rank_index (piece + 1);  
        for (; indx < 16; ++indx) 
             retb = retb | Bitboard[indx][color];
    }
    
    return retb;
}

/* Returns positions of pieces which are frozen of a given color*/
bitboard_t FROZEN (bool color) {
    int i, indx, j;
    bitboard_t retb = 0x0, b = GROUP(color);

    /* iterate over all pieces of given color 
     * NEAR(STRONGER (!color, i)) - All pieces near a stronger enemy
     * !NEAR(b) - Pieces without allies near them
     * */
    for (i = 0; i < R_COUNT - 1; ++i) {
            retb = retb |  ( NEAR(STRONGER(!color, i)) & b & ~NEAR(b));
    }
    
    return retb;
}

/* Returns pieces of given color which are not Frozen */
bitboard_t NOT_FROZEN (bool color) {
    return (GROUP(color) & ~FROZEN(color));
}

/* Legal One step moves possible for all pieces of given color */
bitboard_t ONE_STEP_MOVE (bool color) {
    return (NEAR(NOT_FROZEN(color)) & EMPTY);
}








/************************* Utility Functions *************************/
static std::string hex_to_binary(int s) {
    unsigned n;
    stringstream ss;
    
    ss << hex << s;
    ss >> n;
    
    bitset<8> b(n);
    return b.to_string();
}

const std::string display(bitboard_t b) {
    std::ostringstream ss;
    int iter;
    bitboard_t temp = b;
    
    ss << '\t' << "+-----+----+" << '\n';
    for (iter = 0; iter < 8; ++iter) {
        ss <<  '\t' << '|' << hex_to_binary(temp << (8 * iter) >> 56);
        ss << "|\n";
    }
    ss << '\t' << "+-----+----+" << '\n';
    return ss.str();
}


/* Printing the board of given color and rank */
const std::string display_peices(bitboard_t b, int color, int rank) {
    std::ostringstream ss;
    int iter, j, len;
    bitboard_t temp = b;

    char p = PieceArray[map_rank_index(rank)][color];
    char spc = 32;
    std::string str;
    
    ss << '\t'<< "   A B C D E F G H" << spc << '\n';
    ss << '\t' << " +--------+--------+" << '\n';

    for (iter = 0; iter < 8; ++iter) {
        
       ss << '\t' << (8 - iter) <<'|';
       str = hex_to_binary(temp << (8 * iter) >> 56);
       
       for (j = 0, len = str.length(); j < len; ++j){
            if (str[j] == '1')
                ss << spc << p;
            else
                ss << spc << '.';
       }
       ss << spc << '|' << (8 - iter) << '\n';
    }
    ss << '\t' << " +--------+--------+" << '\n';
    ss << '\t' << "   A B C D E F G H " << spc << '\n';
    return ss.str();
}

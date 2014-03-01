#include "board_util.h"

using namespace std;

const bitboard_t COLUMN_H = 1ULL | (1ULL << 8) | (1ULL << 16) | (1ULL << 24) |(1ULL << 32) | (1ULL << 40) | (1ULL << 48) | (1ULL << 56) ;
const bitboard_t COLUMN_A = (1ULL << 7) | (1ULL << 15) | (1ULL << 23) | (1ULL << 31) | (1ULL << 39) | (1ULL << 47) | (1ULL << 55) | (1ULL << 63) ;
bitboard_t EMPTY          = 0xFFFFFFFF0000;

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
                                 { 'E', 'e'}};

/*
 * Bitboard [0][0] - [15][0] - Gold Pieces bitboards
 * Bitboard [0][1] - [15][0] - Silver Pieces bitboards 
 */
bitboard_t Bitboard[16][2];

/* Movement functions */
bitboard_t MOVE_NORTH (bitboard_t b)       {return ((b) << 8);             }
bitboard_t MOVE_EAST  (bitboard_t b)       {return ((b & ~COLUMN_H) << 1); }
bitboard_t MOVE_WEST  (bitboard_t b)       {return ((b & ~COLUMN_A) >> 1); }
bitboard_t MOVE_SOUTH (bitboard_t b)       {return ((b) >> 8);             }
bitboard_t NEAR  (bitboard_t b)            {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}

/*GOLD RABBITS north move is illegal*/ 
bitboard_t GR_NEAR  (bitboard_t b)         {return ((MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}
/*SILVER RABBITS south move is illegal*/ 
bitboard_t SR_NEAR  (bitboard_t b)         {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)));}

bitboard_t GROUP (bool color) {
    bitboard_t b = 0x0;
    //cout << "value " << Bitboard[2][0]; 
    int i = 0;
    for (i = 0; i < 16; ++i) 
        b = b | Bitboard[i][color];
    
    return b;
}

/* Utility Functions */
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
    
    ss << '\t' << "+------+-----+" << '\n';
    for (iter = 0; iter < 8; ++iter) {
        ss <<  '\t' << '|' << hex_to_binary(temp << (8 * iter) >> 56);
        ss << "|\n";
    }
    ss << '\t' << "+------+-----+" << '\n';
    return ss.str();
}


/* Printing the board of given color and rank */
const std::string display_peices(bitboard_t b, int color, int rank) {
    std::ostringstream ss;
    int iter, j, diff = 0;
    bitboard_t temp = b;

    if (rank < 4)
        diff = 3 - rank;
    
    char p = PieceArray[(10 + rank) - diff][color];
    char spc = 32;
    std::string str;
    
    ss << '\t'<< "   A B C D E F G H" << spc << '\n';
    ss << '\t' << " +--------+--------+" << '\n';

    for (iter = 0; iter < 8; ++iter) {
        
       ss << '\t' << (8 - iter) <<'|';
       str = hex_to_binary(temp << (8 * iter) >> 56);
       
       for (j = 0; j < str.length(); ++j){
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

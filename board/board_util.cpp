#include "board_util.h"

using namespace std;

bitboard_t MOVE_NORTH (bitboard_t b)       {return ((b) << 8);             }
bitboard_t MOVE_EAST  (bitboard_t b)       {return ((b & ~COLUMN_H) << 1); }
bitboard_t MOVE_WEST  (bitboard_t b)       {return ((b & ~COLUMN_A) >> 1); }
bitboard_t MOVE_SOUTH (bitboard_t b)       {return ((b) >> 8);             }
bitboard_t NEAR  (bitboard_t b)            {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}

/*GOLD RABBITS north move is illegal*/ 
bitboard_t GR_NEAR  (bitboard_t b)         {return ((MOVE_EAST(b)) | (MOVE_WEST(b)) | (MOVE_SOUTH(b)));}
/*SILVER RABBITS south move is illegal*/ 
bitboard_t SR_NEAR  (bitboard_t b)         {return ((MOVE_NORTH(b)) | (MOVE_EAST(b)) | (MOVE_WEST(b)));}


static std::string hex_to_binary(int s) {
    unsigned n;
    stringstream ss;
    
    ss << hex << s;
    ss >> n;
    
    bitset<8> b(n);
    return b.to_string();
}


const std::string display(bitboard_t b, int rank) {

    std::ostringstream ss;
    int iter;
    bitboard_t temp = b;

    ss << '\t' << "+----+---+" << '\n';
    for (iter = 0; iter < 8; ++iter) {
        ss <<  '\t' << '|' << hex_to_binary(temp << (8 * iter) >> 56);
        ss << "|\n";
    }
    ss << '\t' << "+----+---+" << '\n';

    return ss.str();
}

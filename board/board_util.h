#ifndef BOARD_UTIL
#define BOARD_UTIL
#include <iostream>
#include <stdint.h>
#include <sstream>
#include <bitset>
#include <string>

#define bitboard_t uint64_t

enum color_e        { GOLD, SILVER, C_COUNT };
enum rank_e         { RABBIT, CAT, DOG, HORSE, CAMEL, ELEPHANT, R_COUNT };
enum direction_e    { NORTH, SOUTH, WEST, EAST, DIR_COUNT };

extern const bitboard_t COLUMN_H;
extern const bitboard_t COLUMN_A;
extern bitboard_t EMPTY;
extern bitboard_t Bitboard[16][2];
extern const char PieceArray[16][2];
extern const bitboard_t TRAPSQRS;
extern const bitboard_t ROW_1;
extern const bitboard_t ROW_8;

bitboard_t MOVE_NORTH (bitboard_t b);
bitboard_t MOVE_EAST  (bitboard_t b);
bitboard_t MOVE_WEST  (bitboard_t b);
bitboard_t MOVE_SOUTH (bitboard_t b);

bitboard_t NEAR (bitboard_t b);
bitboard_t GR_NEAR (bitboard_t b);
bitboard_t SR_NEAR (bitboard_t b);

bitboard_t GROUP (bool color);
bitboard_t STRONGER (bool ,int ); 
bitboard_t WEAKER (bool color, int piece);
bitboard_t FROZEN (bool color);
bitboard_t NOT_FROZEN (bool color);
bitboard_t ONE_STEP_MOVE (bool color);
bitboard_t TWO_STEP_MOVE (bool color, int piece);

bitboard_t is_trapped (bool color);

const std::string display(bitboard_t);
const std::string display_peices(bitboard_t b, int color, int rank);
const std::string print_full_board();

#endif

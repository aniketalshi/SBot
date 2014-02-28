#ifndef BOARD_UTIL
#define BOARD_UTIL
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>


#define bitboard_t uint64_t

enum color_e        { GOLD, SILVER, C_COUNT };
enum rank_e         { RABBIT, CAT, DOG, HORSE, CAMEL, ELEPHANT, R_COUNT };
enum direction_e    { NORTH, SOUTH, WEST, EAST, DIR_COUNT };


static const bitboard_t COLUMN_H = 1ULL | (1ULL << 8) | (1ULL << 16) | (1ULL << 24) |(1ULL << 32) | (1ULL << 40) | (1ULL << 48) | (1ULL << 56) ;
static const bitboard_t COLUMN_A = (1ULL << 7) | (1ULL << 15) | (1ULL << 23) | (1ULL << 31) | (1ULL << 39) | (1ULL << 47) | (1ULL << 55) | (1ULL << 63) ;
static bitboard_t EMPTY          = 0xFFFFFFFF0000;

bitboard_t MOVE_NORTH (bitboard_t b);
bitboard_t MOVE_EAST  (bitboard_t b);
bitboard_t MOVE_WEST  (bitboard_t b);
bitboard_t MOVE_SOUTH (bitboard_t b);

bitboard_t NEAR (bitboard_t b);
bitboard_t GR_NEAR (bitboard_t b);
bitboard_t SR_NEAR (bitboard_t b);

const std::string display(bitboard_t , int );

#endif

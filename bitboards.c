#include "stdio.h"
#include "Core/core.h"
#include "bitboards.h"
#include "enums.h"

U64 setMask[64];
U64 clearMask[64];

// Bit scan table
const int BIT_TABLE[64] = {
        63, 30, 3, 32, 25, 41, 22, 33,
        15, 50, 42, 13, 11, 53, 19, 34,
        61, 29, 2, 51, 21, 43, 45, 10,
        18, 47, 1, 54, 9, 57, 0, 35,
        62, 31, 40, 4, 49, 5, 52, 26,
        60, 6, 23, 44, 46, 27, 56, 16,
        7, 39, 48, 24, 59, 14, 12, 55,
        38, 28, 58, 20, 37, 17, 36, 8
};

// Matt Tayor's Folding Method
int pop_bit(U64 *bb) {
    U64 b = *bb ^ (*bb - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *bb &= (*bb - 1);
    return BIT_TABLE[(fold * 0x783a9b23) >> 26];
}

void clear_bit(U64 *bb, int sq) {
    *bb &= clearMask[(sq)];
}

void set_bit(U64 *bb, int sq) {
    *bb |= setMask[(sq)];
}

// read up on least significant bits
int count_bits(U64 bit) {
    int count = 0;
    while (bit) {
        count++;
        bit &= bit - 1;
    }
    return count;
}

void init_bit_masks() {
    int index = 0;

    for(index = 0; index < 64; index++) {
        setMask[index] = 0ULL;
        clearMask[index] = 0ULL;
    }

    for(index = 0; index < 64; index++) {
        setMask[index] |= (1ULL << index);
        clearMask[index] = ~setMask[index];
    }
}

void print_bitboard(U64 bb) {

    U64 temp = 1ULL;

    int rank = 0;
    int file = 0;
    int sq = 0;
    int sq64 = 0;

    printf("\n");
    for(rank = RANK_8; rank >= RANK_1; --rank) {
        for(file = FILE_A; file <= FILE_H; ++file) {
            sq = FR_2_SQ(file, rank);
            sq64 = SQ_64(sq);

            if((temp << sq64) & bb) {
                printf("X");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}


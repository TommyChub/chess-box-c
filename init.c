#include "Core/core.h"
#include "enums.h"
#include "bitboards.h"
#include <stdlib.h>
#include <stdint.h>

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

U64 PieceKeys[13][BRD_SQ_NUM];
U64 SideKey;
U64 CastleKeys[16];

U64 generate_rand_uint64() {
    U64 result = 0;
    for(int i = 0; i < 64; i +=15) {
        result = result*((U64)RAND_MAX + 1 + rand());
    }
    return result;
}

void init_sq_120_to_64() {

    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;

    for(index = 0; index < BRD_SQ_NUM; ++index) {
        Sq120ToSq64[index] = 65;
    }

    for(index = 0; index < 64; ++index) {
        Sq64ToSq120[index] = 120;
    }

    for(rank = RANK_1; rank <= RANK_8; ++rank) {
        for(file = FILE_A; file <= FILE_H; ++file) {
            sq = FR_2_SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void all_init() {
    init_sq_120_to_64();
    init_bit_masks();
}


#ifndef CHESS_BOX_C_BITBOARDS_H
#define CHESS_BOX_C_BITBOARDS_H

// bitboard.c
void print_bitboard(U64 bb);
void init_bit_masks();
int pop_bit(U64 *bb);
void clear_bit(U64 *bb, int sq);
void set_bit(U64 *bb, int sq);
int count_bits(U64 bit);

#endif //CHESS_BOX_C_BITBOARDS_H

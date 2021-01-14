#ifndef CHESS_BOX_C_BITBOARDS_H
#define CHESS_BOX_C_BITBOARDS_H

// bitboard.c
void PrintBitboard(U64 bb);
void InitBitMasks();
int PopBit(U64 *bb);
void ClearBit(U64 *bb, int sq);
void SetBit(U64 *bb, int sq);
int CountBits(U64 bit);

#endif //CHESS_BOX_C_BITBOARDS_H

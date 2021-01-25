#include "stdio.h"
#include "Core/core.h"
#include "enums.h"

void ResetBoard(Board *pos) {
    int index = 0;

    for(index = 0; index < BRD_SQ_NUM; ++index) {
        pos->pieces[index] = OFFBOARD;
    }

    for(index = 0; index < 64; ++index) {
        pos->pieces[SQ_120(index)] = EMPTY;
    }

    for(index = 0; index < 3; ++index) {
        pos->bigPiece[index] = 0;
        pos->majorPiece[index] = 0;
        pos->minorPiece[index] = 0;
        pos->pawns[index] = 0ULL;
    }

    for(index = 0; index < 13; ++index) {
        pos->pieceNum[index] = 0;
    }

    pos->KingSq[WHITE] = pos->KingSq[BLACK] = NO_SQ;

    pos->side = BOTH;
    pos->enPas = NO_SQ;
    pos->fiftyMove = 0;

    pos->ply = 0;
    pos->hisPly = 0;

    pos-> catlePerm = 0;

    pos->posKey = 0ULL;
}

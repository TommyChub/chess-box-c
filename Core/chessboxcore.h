#ifndef CHESSBOXC_CHESSBOX_CORE_H
#define CHESSBOXC_CHESSBOX_CORE_H

#include "stdlib.h"

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed",#n); \
printf(" On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

/* MACROS */
#define NAME "ChessBoxC V1.0"
#define BRD_SQ_NUM 120
#define MAXGAMEMOVES 2048
#define FR2SQ(f,r) ( (21 + (f)) ) + ( (r) * 10 )
#define SQ64(sq120) Sq120ToSq64[sq120]
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb,sq) ((bb) &= ClearMask[(sq)])
#define SETBIT(bb,sq) ((bb) |= SetMask[(sq)])

/* STRUCTS */

typedef struct {

    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;

} S_UNDO;

typedef struct {

    int pieces[BRD_SQ_NUM];
    U64 pawns[3];

    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int catlePerm;

    U64 posKey;

    int pieceNum[13];
    int bigPiece[3];
    int majorPiece[3];
    int minorPiece[3];

    S_UNDO history[MAXGAMEMOVES];

    // piece list
    int pList[13][10];

} S_BOARD;

/* GLOBALS */
extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];
extern U64 SetMask[64];
extern U64 ClearMask[64];

/* FUNCTIONS */

//init.c
extern void AllInit();

#endif
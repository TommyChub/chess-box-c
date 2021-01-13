#include "chessboxcore.h"
#include "../enums.h"
#include "../bitboards.h"
#include <stdio.h>

int main() {
    AllInit();
    int index = 0;
    U64 bitBoard = 0ULL;

    SETBIT(bitBoard, 61);
    PrintBitboard(bitBoard);

    CLRBIT(bitBoard, 61);
    PrintBitboard(bitBoard);

    return 0;
}
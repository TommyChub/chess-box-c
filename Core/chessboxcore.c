#include "chessboxcore.h"
#include "../enums.h"
#include "../bitboards.h"
#include "../init.h"
#include <stdio.h>

int main() {
    AllInit();
    U64 bitBoard = 0ULL;

    SetBit(&bitBoard, 61);
    PrintBitboard(bitBoard);

    ClearBit(&bitBoard, 61);
    PrintBitboard(bitBoard);

    return 0;
}
#include "core.h"
#include "../enums.h"
#include "../bitboards.h"
#include "../init.h"s
#include <stdio.h>
#include <stdint.h>

int main() {
    all_init();
    uint64_t test = generate_rand_uint64();
    printf("Result: %llu", test);

    return 0;
}
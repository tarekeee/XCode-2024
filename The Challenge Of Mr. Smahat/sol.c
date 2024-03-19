#include <stdio.h>

int div16(int x) {
    /* Compute bias to be either 0 (x >= 0) or 15 (x < 0) */
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    for (int i = 1; i <= test_cases; i++) {
        int x;
        scanf("%d", &x);
        printf("Case %d: %d\n", i, div16(x));
    }
}
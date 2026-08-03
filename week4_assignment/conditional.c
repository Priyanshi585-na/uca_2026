#include <stdio.h>


int conditional(int x, int y, int z) {
    int mask = ~(!x) + 1;
    return (~mask & y) | (mask & z);
}

int main() {
    printf("%d\n", conditional(2,4,5));

    return 0;
}

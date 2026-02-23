#include <stdio.h>

int main() {
    int a, b, t;
    scanf("%d %d", &a, &b);
    t = 10 + 2 * (25 - a + b);
    printf("%d", t < 0 ? 0 : t);
    return 0;
}
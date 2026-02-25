#include <stdio.h>

int main() {
    int n, a, b, x;
    for(scanf("%d", &n);n--;) {
        scanf("%d %d %d", &a, &b, &x);
        printf("%d\n", a*(x-1)+b);
    }
    return 0;
}

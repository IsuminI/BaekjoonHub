#include <stdio.h>

int main() {
    int t, n, sum=0;
    for(scanf("%d", &t);t--;) {
        scanf("%d", &n);
        sum += n;
    }
    printf("%d", sum);
    return 0;
}
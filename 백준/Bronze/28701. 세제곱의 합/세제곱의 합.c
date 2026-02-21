#include <stdio.h>
#include <math.h>
int main() {
    int n, sum=0, sums=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        sum += i;
        sums += i*i*i;
    }
    printf("%d\n%d\n%d", sum, sum*sum, sums);
    return 0;
}
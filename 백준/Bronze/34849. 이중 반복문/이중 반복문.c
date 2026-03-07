#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 10000) printf("Accepted");
    else printf("Time limit exceeded");
    return 0;
}
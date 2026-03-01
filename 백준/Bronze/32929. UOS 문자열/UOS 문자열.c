#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    n--;
    printf("%c", n%3==0?'U':n%3==1?'O':'S');
    return 0;
}
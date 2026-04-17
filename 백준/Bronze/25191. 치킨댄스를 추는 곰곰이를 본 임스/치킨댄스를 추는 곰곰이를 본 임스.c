#include <stdio.h>

int main() {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d",n<a/2+b?n:a/2+b);
    return 0;
}
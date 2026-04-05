#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b&&b==c) puts("*");
    else if(a==b) puts("C");
    else if(b==c) puts("A");
    else puts("B");
    return 0;
}
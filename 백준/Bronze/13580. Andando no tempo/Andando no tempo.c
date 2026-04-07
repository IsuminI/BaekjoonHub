#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b+c||b==a+c||c==a+b) puts("S");
    else if(a==b||a==c||b==c) puts("S");
    else puts("N");
    return 0;
}
#include <stdio.h>

int main() {
    int a,b,c,d,e,f,m;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    m=a;
    m=m<b?m:b;
    m=m<c?m:c;
    m=m<d?m:d;
    printf("%d\n",a+b+c+d-m+(e<f?f:e));
    return 0;
}
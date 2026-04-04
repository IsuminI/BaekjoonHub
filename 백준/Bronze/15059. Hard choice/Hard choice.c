#include <stdio.h>

int main() {
    int a,b,c,d,e,f,s=0;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    s+=a<d?d-a:0;
    s+=b<e?e-b:0;
    s+=c<f?f-c:0;
    printf("%d",s);
    return 0;
}
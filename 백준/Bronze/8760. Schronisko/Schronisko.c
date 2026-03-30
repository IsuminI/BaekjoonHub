#include <stdio.h>

int main() {
    int t,a,b;
    for(scanf("%d",&t);t--;){
        scanf("%d%d",&a,&b);
        if(a%2==0) printf("%d\n",a/2*b);
        else if(b%2==0) printf("%d\n",b/2*a);
        else printf("%d\n",a/2+a*(b/2));
    }
    return 0;
}
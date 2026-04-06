#include <stdio.h>

int main() {
    int n,sum=0;
    char a[10001], b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %c",&b);
        sum += a[i]==b?1:0;
    }
    printf("%d", sum);
    return 0;
}
#include <stdio.h>
#include <string.h>
int main() {
    int t;
    char a[999];
    for(scanf("%d ",&t);t--;) {
        gets(a);
        printf("%d\n",strlen(a));
    }
    return 0;
}
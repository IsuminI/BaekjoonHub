#include <stdio.h>

int main() {
    int t;
    char arr[99];
    for(scanf("%d ",&t);t--;){
        gets(arr);
        if(arr[0]=='A') {
            if(arr[1]=='l') puts("204");
            else puts("302");
        } 
        if(arr[0]=='D') puts("207");
        if(arr[0]=='C') puts("B101");
        if(arr[0]=='N') puts("303");
        if(arr[0]=='S') puts("501");
        if(arr[0]=='T') puts("105");
    }
    return 0;
}
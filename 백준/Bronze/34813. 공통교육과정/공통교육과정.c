#include <stdio.h>

int main() {
    char a[9];
    gets(a);
    if(a[0]=='F')puts("Foundation");
    if(a[0]=='C')puts("Claves");
    if(a[0]=='V')puts("Veritas");
    if(a[0]=='E')puts("Exploration");
    return 0;
}
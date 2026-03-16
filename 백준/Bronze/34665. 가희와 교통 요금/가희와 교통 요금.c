#include <stdio.h>
#include <string.h>
int main() {
    char a[21], b[21];
    scanf("%s %s", &a, &b);
    puts(!strcmp(a, b) ? "0" : "1550");
    return 0;
}
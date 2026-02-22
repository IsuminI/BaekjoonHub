#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n >= 620) puts("Red");
    else if(n >= 590) puts("Orange");
    else if(n >= 570) puts("Yellow");
    else if(n >= 495) puts("Green");
    else if(n >= 450) puts("Blue");
    else if(n >= 425) puts("Indigo");
    else if(n >= 380) puts("Violet");
    return 0;
}
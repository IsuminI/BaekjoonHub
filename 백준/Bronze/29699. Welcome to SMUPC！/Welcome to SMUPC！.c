#include <stdio.h>

int main() {
    char* arr = "WelcomeToSMUPC";
    int n;
    scanf("%d", &n);
    printf("%c", arr[((n-1)%14)]);
    return 0;
}

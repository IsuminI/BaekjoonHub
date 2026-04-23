#include <stdio.h>
#include <string.h>
char a[100001];
int A,B;
int main() {
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='A')A++;
        else B++;
    }
    printf("%d : %d",A,B);
    return 0;
}
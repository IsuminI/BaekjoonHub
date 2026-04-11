#include <stdio.h>
#include <string.h>
char a[26];
int b[26];
int main() {
    int i;
    scanf("%s",&a);
    for(i=0;i<strlen(a);i++) {
        b[a[i]-'A']++;
    }
    for(i=0;i<26;i++) {
        if(!b[i]) printf("%c", i+'A');
    }
    return 0;
}
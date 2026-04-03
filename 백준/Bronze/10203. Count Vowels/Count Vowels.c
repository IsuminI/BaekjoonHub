#include <stdio.h>
#include <string.h>
int main() {
    int t,b;
    char a[101];
    for(scanf("%d ",&t);b=0,t--;){
        gets(a);
        for(int i=0;i<strlen(a);i++){
            switch(a[i]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                b++;
                break;
            }
        }
        printf("The number of vowels in %s is %d.\n",a,b);
    }
    return 0;
}
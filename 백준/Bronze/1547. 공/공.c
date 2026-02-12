#include <stdio.h>

int main() {

    int m, a, b;

    scanf("%d", &m);

    int l = 1;

    for(int i=0; i<m; i++) {

        scanf("%d %d", &a, &b);

        if(a == l) l = b;

        else if(b == l) l = a;

    }

    printf("%d", l);

    return 0;

}
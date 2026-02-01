#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0;
    char a;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            scanf(" %c", &a);
            if(a == 'F') {
                if(i%2 == 0 && j%2 == 0) cnt++;
                else if(i%2 == 1 && j%2 == 1) cnt++;
            } 
        }
    }
    printf("%d", cnt);

    return 0;
}

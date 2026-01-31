#include <bits/stdc++.h>
using namespace std;
int main() {

    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    int cnt=1;
    while(1) {
        a = (a+1) / 2;
        b = (b+1) / 2;

        if(a == b) {
            printf("%d", cnt);
            break;
        }
        cnt++;
    }
    return 0;
}
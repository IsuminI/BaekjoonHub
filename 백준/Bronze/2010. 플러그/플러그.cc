#include <bits/stdc++.h>
using namespace std;
int t, n, sum;
int main() {
    for(scanf("%d", &t);t--;) {
        scanf("%d", &n);
        sum += n;
        if(t) sum--;
    }
    printf("%d", sum);
    return 0;
}


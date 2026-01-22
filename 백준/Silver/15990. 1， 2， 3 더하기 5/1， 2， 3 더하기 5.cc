#include <bits/stdc++.h>
#define N 1000000009
using namespace std;
int dp[100001][4];
int main() {

    for(int i=1; i<=100000; i++) {
        if(i < 1) dp[i][1] = 0;
        else if(i == 1) dp[i][1] = 1;
        else dp[i][1] = (dp[i-1][2] % N + dp[i-1][3] % N) % N;

        if(i < 2) dp[i][2] = 0;
        else if(i == 2) dp[i][2] = 1;
        else dp[i][2] = (dp[i-2][1] % N + dp[i-2][3] % N) % N;
        
        if(i < 3) dp[i][3] = 0;
        else if(i == 3) dp[i][3] = 1;
        else dp[i][3] = (dp[i-3][1] % N + dp[i-3][2] % N) % N;
    }
    int t, n;
    for(scanf("%d", &t);t--;) {
        scanf("%d", &n);
        printf("%d\n", ((dp[n][1] % N + dp[n][2] % N) % N + dp[n][3] % N) % N);
    }
    return 0;
}
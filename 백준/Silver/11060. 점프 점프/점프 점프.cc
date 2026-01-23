#include <bits/stdc++.h>
using namespace std;
int n, a, dp[1101];
int main() {

    scanf("%d", &n);
    for(int i=0; i<=1101; i++) dp[i] = 987654321;
    dp[1] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a);
        for(int j=1; j<=a; j++) {
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    if(dp[n] == 987654321) printf("-1");
    else printf("%d", dp[n]);
    

    return 0;
}
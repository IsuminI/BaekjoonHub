#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int dp[1000001];
int check[1000001];
int dfs(int x, int cnt) {
    if(x < 1 || x > f) return 987654321;
    if(dp[x]) return dp[x];
    if(check[x]) return 987654321;
    check[x] = 1;

    if(x < g) {
        if(u == 0) {
            return 987654321;   
        }
        if((g-x) % u == 0) return dp[x] = (g-x) / u + cnt;
        else {
            return dp[x] = min(dfs(x+u, cnt + 1), dfs(x-d, cnt + 1));
        }
    }
    else if(x > g) {
        if(d == 0) {
            return 987654321;
        }
        if((x-g) % d == 0) return dp[x] = (x-g) / d + cnt;
        else {
            return dp[x] = min(dfs(x+u, cnt + 1), dfs(x-d, cnt + 1));
        }
    }   
    else {
        return cnt;
    }
}

int main() {
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    int answer = dfs(s, 0);
    if(answer == 987654321) {
        printf("use the stairs");
    }
    else printf("%d", answer);
    return 0;
}
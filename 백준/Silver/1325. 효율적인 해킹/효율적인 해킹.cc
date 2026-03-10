#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, dp[10001], check[10001];
vector<int> v[10001];
int dfs(int x) {
    if(check[x]) return 0;
    check[x] = 1;
    int t = v[x].size();
    int sum = 0;
    for(int i=0; i<t; i++) {
        int y = v[x][i];
        sum += dfs(y);
    }
    return sum + 1; 
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        v[b].push_back(a);
    }
    int max_cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) check[j] = 0;
        dp[i] = dfs(i);
        max_cnt = max(max_cnt, dp[i]);
    }
    for(int i=1; i<=n; i++) {
        if(max_cnt == dp[i]) printf("%d ", i);
    }
    
    return 0;
}
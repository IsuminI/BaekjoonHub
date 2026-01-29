#include <bits/stdc++.h>
using namespace std;
int n, w, check[11];
int answer = 987654321;
vector<int> v[11];

void dfs(int start, int cur, int cnt, int sum) {
    if(cnt == n) {
        if(v[cur][start] != 0) {
            sum += v[cur][start];
            answer = min(answer, sum);
        }
        return;
    }

    for(int i=0; i<n; i++) {
        if(!check[i] && v[cur][i] != 0) {
            check[i] = 1;
            dfs(start, i, cnt+1, sum+v[cur][i]);
            check[i] = 0;
        }
    }
}
int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &w);
            v[i].push_back(w);
        }
    }
    for(int i=0; i<n; i++) {
        check[i] = 1;
        dfs(i, i, 1, 0);
        check[i] = 0;
    }
    printf("%d", answer);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100001];
int n, m, r, u, v;
int check[100001];
int arr[100001];
int cnt;
void dfs(int x) {
    check[x] = 1;
    arr[x] = ++cnt;
    sort(vec[x].begin(), vec[x].end(), greater<int>());
    int t = vec[x].size();
    for(int i=0; i<t; i++) {
        if(!check[vec[x][i]]) dfs(vec[x][i]);
    }
}
int main() {

    scanf("%d %d %d", &n, &m, &r);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(r);

    for(int i=1; i<=n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
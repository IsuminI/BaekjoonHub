#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int c[100001];
int d[100001];
int parent[100001][21];
vector<int> v[100001];
void dfs(int index, int depth) {
    c[index] = 1;
    d[index] = depth;
    int t = v[index].size();
    for(int i=0; i<t; i++) {
        int x = v[index][i];
        if(!c[x]) {
            parent[x][0] = index;
            dfs(x, depth + 1);
        }
    }
}
void setParent() {
    dfs(1, 0);
    for(int j=1; j<21; j++) {
        for(int i=1; i<=n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}
int lca(int x, int y) {
    if(d[x] > d[y]) {
        swap(x, y);
    }
    for(int i=20; i>=0; i--) {
        if(d[y] - d[x] >= (1 << i)) {
            y = parent[y][i];
        }
    }
    if(x == y) return x;
    for(int i=20; i>=0; i--) {
        if(parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    setParent();

    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
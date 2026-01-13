#include <bits/stdc++.h>
using namespace std;
int r, c, k, check[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char arr[6][6];
int dfs(int x, int y, int cnt) {

    if(x < 0 || x >= r || y < 0 || y >= c) return 0;
    if(arr[x][y] == 'T') return 0;
    if(check[x][y]) return 0;
    if(x == 0 && y == c-1) {
        if(cnt == k) {
            return 1;
        }
        return 0;
    }

    check[x][y] = 1;

    int sum = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += dfs(nx, ny, cnt+1);
    }

    check[x][y] = 0;
    return sum;
}

int main() {
    scanf("%d %d %d", &r, &c, &k);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    printf("%d", dfs(r-1, 0, 1));

    return 0;
}

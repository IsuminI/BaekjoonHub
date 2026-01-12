#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, check[601][601];
char arr[601][601];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(arr[x][y] == 'X') return 0;
    if(check[x][y]) return 0;
    
    check[x][y] = 1;

    int sum = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += dfs(nx, ny);
    }
    return arr[x][y] == 'P' ? sum + 1 : sum;

}

int main() {

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'I') {
                x = i;
                y = j;
            }
        }
    }
    int answer = dfs(x, y);
    if(!answer) printf("TT");
    else printf("%d", answer);

    return 0;
}
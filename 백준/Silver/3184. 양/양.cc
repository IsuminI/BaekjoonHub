#include <bits/stdc++.h>
using namespace std;
int r, c, O, V, o, v;
int check[251][251];
char arr[251][251];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if(x < 0 || x >= r || y < 0 || y >= c) return;
    if(arr[x][y] == '#') return;
    if(check[x][y]) return;
    check[x][y] = 1;
    
    if(arr[x][y] == 'o') o++;
    else if(arr[x][y] == 'v') v++;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {

    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'o') O++;
            else if(arr[i][j] == 'v') V++;
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(check[i][j]) continue;
            o = 0;
            v = 0;
            dfs(i, j);

            if(o > v) V -= v;
            else O -= o;
        }
    }
    printf("%d %d", O, V);
    return 0;
}
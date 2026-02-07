#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, t, arr[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int isEmpty() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]) return 0;
        }
    }
    return 1;
}

void Dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(arr[x][y] != 0) return;
    arr[x][y] = 9;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Dfs(nx, ny);
    }
}

void isMelt() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 1) {
                if(arr[i-1][j] == 9 || arr[i+1][j] == 9) arr[i][j] = 2;
                if(arr[i][j-1] == 9 || arr[i][j+1] == 9) arr[i][j] = 2;
            }
        }
    }
}

int Melt() {
    int melt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 2) {
                arr[i][j] = 9;
                melt++;
            }
        }
    }
    return melt;
}

void toZero() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 9) {
                arr[i][j] = 0;
            }
        }
    }
}
int main() {

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) cnt++;
        }
    }

    int melt = 0;
    while(1) {
        if(isEmpty()) break;
        Dfs(0, 0);
        isMelt();
        melt = Melt();
        toZero();
        t++;
        if(isEmpty()) {
            break;
        }
        else cnt -= melt;
    }
    printf("%d\n%d", t, cnt);
    return 0;
}
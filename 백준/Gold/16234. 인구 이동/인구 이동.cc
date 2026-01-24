#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int sum;
    int cnt;
}st;
int n, l, r;
int arr[51][51], visitt[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int flag;
map<int, st> m;
void dfs(int x, int y, int c_cnt) {

    visitt[x][y] = c_cnt;
    if(m.find(c_cnt) != m.end()) {
        m[c_cnt].sum += arr[x][y];
        m[c_cnt].cnt++;
    }
    else {
        m[c_cnt] = {arr[x][y], 1};
    }
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visitt[nx][ny]) continue;
        int diff = abs(arr[x][y] - arr[nx][ny]);
        if(l <= diff && diff <= r) {
            flag = 1;
            dfs(nx, ny, c_cnt);
        }
    }
}
int main() {

    scanf("%d %d %d", &n, &l, &r);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int cnt = 0;
    while(1) {
        flag = 0;
        int c_cnt = 1;
        m.clear();
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) visitt[i][j] = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visitt[i][j]) {
                    dfs(i, j, c_cnt++);
                }
            }
        }

        if(flag) {
            cnt++;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    int nsum = m[visitt[i][j]].sum / m[visitt[i][j]].cnt;
                    arr[i][j] = nsum;
                }
            }   
        }
        else break;
    }
    printf("%d", cnt);


    return 0;
}
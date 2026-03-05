#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x;
    int y;
    int cnt;
} st;

int tc, n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char arr[1001][1001];
unsigned char vis[1001][1001];

queue<st> q;
queue<pair<int,int> > fireQ;

void FireBFS() {
    int fs = fireQ.size();
    for(int i=0; i<fs; i++) {
        int x = fireQ.front().first;
        int y = fireQ.front().second;
        fireQ.pop();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == '#' || arr[nx][ny] == '*') continue;

            arr[nx][ny] = '*';
            fireQ.push({nx, ny});
        }
    }
}

int main() {
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &m);

        while(!q.empty()) q.pop();
        while(!fireQ.empty()) fireQ.pop();

        for(int i=0; i<m; i++) memset(vis[i], 0, n);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                scanf(" %c", &arr[i][j]);
                if(arr[i][j] == '@') {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
                else if(arr[i][j] == '*') {
                    fireQ.push({i, j});
                }
            }
        }

        int min_exit = 987654321;

        while(!q.empty()) {
            FireBFS();
            int qs = q.size();
            for(int k=0; k<qs; k++) {
                st s = q.front(); q.pop();

                for(int dir=0; dir<4; dir++) {
                    int nx = s.x + dx[dir];
                    int ny = s.y + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        min_exit = min(min_exit, s.cnt + 1);
                        continue;
                    }
                    if(arr[nx][ny] != '.') continue;
                    if(vis[nx][ny]) continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny, s.cnt + 1});
                }
            }
            if(min_exit != 987654321) break;
        }

        if(min_exit == 987654321) printf("IMPOSSIBLE\n");
        else printf("%d\n", min_exit);
    }
    return 0;
}
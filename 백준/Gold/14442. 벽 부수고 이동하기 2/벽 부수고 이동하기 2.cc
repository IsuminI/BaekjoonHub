#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int n, m, k;
int dp[1001][1001][11];
int nx[4] = {-1, 1, 0, 0};
int ny[4] = {0, 0, -1, 1};

typedef struct {
    int x, y, cur_k;
} st;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int b=0; b<=k; b++) dp[i][j][b] = -1;
        }
    }

    queue<st> q;
    dp[1][1][0] = 1;
    q.push({1, 1, 0});

    while(!q.empty()) {
        st cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int cur_k = cur.cur_k;

        if(x == n && y == m) {
            printf("%d", dp[x][y][cur_k]);
            return 0;
        }

        for(int i=0; i<4; i++) {
            int dx = x + nx[i];
            int dy = y + ny[i];

            if(dx < 1 || dx > n || dy < 1 || dy > m) continue;

            if(arr[dx][dy] == '1') {
                if(cur_k == k) continue;
                if(dp[dx][dy][cur_k + 1] != -1) continue;

                dp[dx][dy][cur_k + 1] = dp[x][y][cur_k] + 1;
                q.push({dx, dy, cur_k + 1});
            }
            else {
                if(dp[dx][dy][cur_k] != -1) continue;

                dp[dx][dy][cur_k] = dp[x][y][cur_k] + 1;
                q.push({dx, dy, cur_k});
            }
        }
    }

    printf("-1");
    return 0;
}
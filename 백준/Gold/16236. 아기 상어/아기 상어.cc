#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y, cnt;
}st;
int n, x, y, arr[21][21], now_size=2, eat_size;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int check[21][21];
st point;

struct compare {
    bool operator()(st a, st b) {
        if(a.cnt == b.cnt) {
            if(a.x == b.x) return a.y > b.y;
            return a.x > b.x;
        }
        return a.cnt > b.cnt;
    }
};

int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 9) {
                x = i;
                y = j;
                arr[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    for(;;) {
        priority_queue<st, vector<st>, compare> pq;
        int min_cnt = 987654321;
        int new_x, new_y;
        pq.push({x, y, 0});
        while(!pq.empty()) {
            if(min_cnt != 987654321) break;
            st point = pq.top();
            pq.pop();

            if(check[point.x][point.y]) continue;
            check[point.x][point.y] = 1;

            if(arr[point.x][point.y] != 0 && arr[point.x][point.y] < now_size) {
                new_x = point.x;
                new_y = point.y;
                min_cnt = point.cnt;
                break;
            }

            for(int i=0; i<4; i++) {
                int xx = point.x + dx[i];
                int yy = point.y + dy[i];

                if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if(now_size < arr[xx][yy]) continue;
                if(point.cnt >= min_cnt) continue;
                if(now_size < arr[xx][yy]) continue;
                
                pq.push({xx, yy, point.cnt + 1});
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) check[i][j] = 0;
        
        if(min_cnt == 987654321) {
            printf("%d", cnt);
            break;
        }
        
        x = new_x;
        y = new_y;
        arr[x][y] = 0;
        eat_size++;
        cnt += min_cnt;
        
        if(eat_size == now_size) {
            now_size++;
            eat_size = 0;
        }
    }

    return 0;
}
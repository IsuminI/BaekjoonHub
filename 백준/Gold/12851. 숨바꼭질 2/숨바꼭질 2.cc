#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int point;
    int time;
}st;
int check[100001];
int main() {

    int n, k;
    int min_time = 987654321;
    int cnt = 0;
    queue<st> q;
    scanf("%d %d", &n, &k);
    
    q.push({n, 0});
    while(!q.empty()) {
        st x = q.front();
        q.pop();

        check[x.point] = 1;
        
        if(min_time < x.time) break;
        if(x.point == k) {
            min_time = x.time;
            cnt++;
        }
        else {
            if(x.point - 1 >= 0 && !check[x.point - 1]) q.push({x.point - 1, x.time + 1});
            if(x.point + 1 <= 100000 && !check[x.point + 1]) q.push({x.point + 1, x.time + 1});
            if(x.point * 2 <= 100000 && !check[x.point * 2]) q.push({x.point * 2, x.time + 1});
        }
    }

    printf("%d\n%d", min_time, cnt);
    return 0;
}

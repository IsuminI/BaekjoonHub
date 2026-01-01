#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int index;
    int p;
}st;
queue<st> q;
priority_queue<int> pq;
int main() {

    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, m, p;
        scanf("%d %d", &n, &m);
        for(int j=0; j<n; j++) {
            scanf("%d", &p);
            pq.push(p);
            q.push({j, p});
        }

        int cnt = 1;
        while(cnt <= n) {
            if(q.front().p == pq.top()) {
                if(q.front().index == m) {
                    printf("%d\n", cnt);
                    break;
                }
                cnt++;
                pq.pop();
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        while(!pq.empty()) pq.pop();
        while(!q.empty()) q.pop();
    }
    return 0;
}
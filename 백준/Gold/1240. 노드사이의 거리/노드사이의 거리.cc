#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int next;
    int dis;
}st;
int n, m, a, b, c, dis[1001];
vector<st> v[1001];

struct compare {
    bool operator()(st a, st b) {
        return a.dis > b.dis;
    }
};
void f(int start) {
    priority_queue<st, vector<st>, compare> pq;
    pq.push({start, 0});
    dis[start] = 0;

    while(!pq.empty()) {
        st x = pq.top();
        pq.pop();

        if(dis[x.next] < x.dis) continue;

        for(int i=0; i<v[x.next].size(); i++) {
            st y = v[x.next][i];
            if(x.dis + y.dis < dis[y.next]) {
                dis[y.next] = x.dis + y.dis;
                pq.push({y.next, dis[y.next]});
            }
        }
    }
}


int main() {

    scanf("%d %d", &n, &m);
    for(int i=0; i<n-1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        for(int i=1; i<=n; i++) dis[i] = 987654321;
        f(a);
        printf("%d\n", dis[b]);
    }
    return 0;
}

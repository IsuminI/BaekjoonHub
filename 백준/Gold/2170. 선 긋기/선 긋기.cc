#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y;
}st;

struct compare {
    bool operator()(st a, st b) {
        return a.x > b.x;
    }
};

priority_queue<st, vector<st>, compare> pq;
int main() {
    int n, x, y, sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        pq.push({x, y});
    }
    int l = pq.top().x;
    int r = pq.top().y;
    pq.pop();

    while(!pq.empty()) {
        st a = pq.top();
        pq.pop();
        if(a.x > r) {
            sum += r-l;
            l = a.x;
            r = a.y;
        }
        else r = max(r, a.y);
    }

    sum += r-l;
    printf("%d", sum);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, w, l, a;
int main() {
    int sum = 0;
    int cnt = 0;
    queue<int> q;
    scanf("%d %d %d", &n, &w, &l);

    for(int i=0; i<w; i++) {
        q.push(0);
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &a);

        sum -= q.front();
        q.pop();

        if(sum + a > l) {
            while(sum + a > l) {
                sum -= q.front();
                q.pop();
                q.push(0);
                cnt++;
            }
        }
        q.push(a);
        sum += a;
        cnt++;
    }
    while(sum > 0) {
        sum -= q.front();
        q.pop();
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
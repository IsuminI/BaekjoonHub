#include <bits/stdc++.h>
using namespace std;
int n, m, a;
vector<int> v;
vector<int> vv;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &a);
        vv.push_back(a);
    }
    sort(vv.rbegin(), vv.rend());


    if(vv[0] > v[0]) {
        printf("-1");
        return 0;
    }

    vector<int> used(m, 0);
    vector<int> p(n, 0);
    int move = 0;

    for(int i=1;;i++) {
        for(int j=0; j<n; j++) {
            if(move == m) break;

            while(p[j] < m && (used[p[j]] || vv[p[j]] > v[j])) p[j]++;
            if(p[j] < m) {
                used[p[j]] = 1;
                move++;
                p[j]++;
            }
        }

        if(move == m) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x;
    int y;
    int sum;
}st;

int n, m, arr[51][51], cnt, answer = 987654321;
vector<st> home, chicken;
st selectt[51];
int diff(st a, st b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int min_dis() { 
    int min_sum = 0;
    int t = home.size();
    for(int i=0; i<t; i++) {
        int sum = 987654321;
        for(int j=0; j<cnt; j++) {
            sum = min(sum, diff(home[i], selectt[j]));
        }
        min_sum += sum;
    }
    return min_sum;
}
void dfs(int s) {
    if(cnt == m) {
        int sum = min_dis();
        answer = min(answer, sum);
        return;
    }
    int ct = chicken.size();
    for(int i=s; i<ct; i++) {
        selectt[cnt] = chicken[i];
        cnt++;
        dfs(i+1);
        cnt--;
    }
}
int main() {
    int m_cnt = 0;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) home.push_back({i, j, 0});
            else if(arr[i][j] == 2) chicken.push_back({i, j, 0});
        }
    }

    dfs(0);

    printf("%d", answer);

    return 0;
}
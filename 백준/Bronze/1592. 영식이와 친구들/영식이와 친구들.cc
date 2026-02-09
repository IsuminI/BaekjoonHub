#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main() {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    
    int cur = 1;
    int cnt = 0;
    while(1) {
        arr[cur]++;
        if(arr[cur] == m) {
            printf("%d", cnt);
            break;
        }
        cnt++;

        if(arr[cur] % 2 == 1) {
            cur += l;
            if(cur > n) cur -= n;
        }
        else {
            cur -= l;
            if(cur < 1) cur += n;
        }
    }
    return 0;
}
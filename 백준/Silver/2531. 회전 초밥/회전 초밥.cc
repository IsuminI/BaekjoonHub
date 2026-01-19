#include <bits/stdc++.h>
using namespace std;
int n, d, k, c;
int arr[60002], check[3001];
int main() {
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        arr[i+n] = arr[i];
    }
    
    int max_cnt = 0;
    int cnt = 0;
    for(int i=0; i<k; i++) {
        if(!check[arr[i]]) {
            check[arr[i]] = 1;
            cnt++;
        }
        else {
            check[arr[i]]++;
        }
    }
    if(check[c]) max_cnt = max(max_cnt, cnt);
    else max_cnt = max(max_cnt, cnt+1);
    for(int i=1; i<n; i++) {
        if(!--check[arr[i-1]]) cnt--;

        if(!check[arr[i+k-1]]) {
            check[arr[i+k-1]] = 1;
            cnt++;
        }
        else {
            check[arr[i+k-1]]++;
        }

        if(check[c]) max_cnt = max(max_cnt, cnt);
        else max_cnt = max(max_cnt, cnt+1);
    }
    printf("%d", max_cnt);
    return 0;
}
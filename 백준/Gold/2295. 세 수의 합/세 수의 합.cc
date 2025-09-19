#include <bits/stdc++.h>
using namespace std;
long long int n, arr[1001];
set<long long int> s;
int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            s.insert(arr[i] + arr[j]);
        }
    }

    sort(arr, arr+n);

    int flag = 0;
    for(int i=n-1; i>=0; i--) {
        if(flag) break;
        for(int j=0; j<=i; j++) {
            long long int target = arr[i] - arr[j];
            if(s.find(target) != s.end()) {
                printf("%lld", arr[i]);
                flag = 1;
                break;
            }
        }
    }
    return 0;
}
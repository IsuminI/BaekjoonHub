#include <bits/stdc++.h>
using namespace std;
long long int t, n, arr[1000001];
int main() {
    for(scanf("%lld", &t);t--;) {
        scanf("%lld", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &arr[i]);
        }

        long long int max_value = 0;
        long long int sum = 0;
        for(int i=n-1; i>=0; i--) {
            if(max_value < arr[i]) {
                max_value = arr[i];
            }
            else {
                sum += max_value - arr[i];
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

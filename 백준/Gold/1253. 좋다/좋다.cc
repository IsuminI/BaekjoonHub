#include <bits/stdc++.h>
using namespace std;
long long int n, arr[2001];
set<long long int> s;
int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n);

    int answer = 0;
    for(int i=0; i<n; i++) {
        int flag = 0;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(flag) break;
            int target = arr[i] - arr[j];

            int left, right, mid;
            int l, r;
            left = 0;
            right = n-1;
            while(left <= right) {
                mid = (left + right) / 2;
                if(arr[mid] == target) {
                    right = mid - 1;
                }
                else if(arr[mid] > target) right = mid - 1;
                else left = mid + 1;
            }

            l = left;

            left = 0;
            right = n-1;
            while(left <= right) {
                mid = (left + right) / 2;
                if(arr[mid] == target) {
                    left = mid + 1;
                }
                else if(arr[mid] > target) right = mid - 1;
                else left = mid + 1;        
            }
            r = right;

            int cnt = (r-l+1);
            if(arr[i] == target) cnt--;
            if(arr[j] == target) cnt--;
            if(cnt > 0) {answer++; break;};
        }
    }
    printf("%d", answer);


    return 0;
}
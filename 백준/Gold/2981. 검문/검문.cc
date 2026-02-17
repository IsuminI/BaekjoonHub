#include <bits/stdc++.h>
using namespace std;
int arr[101], n;
vector<int> v;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++) {
        v.push_back(arr[i+1] - arr[i]);
    }
    int t = v.size();
    int k = v[0];
    for(int i=1; i<t; i++) {
        k = gcd(k, v[i]);
    }
    for(int i=2; i<=k; i++) {
        if(k % i == 0) printf("%d ", i);
    }
    return 0;
}
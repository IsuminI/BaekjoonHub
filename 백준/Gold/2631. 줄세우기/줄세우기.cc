#include <bits/stdc++.h>
using namespace std;
int n, arr[201];
vector<int> v;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    v.push_back(arr[0]);
    for(int i=1; i<n; i++) {
        if(v[v.size() - 1] < arr[i]) v.push_back(arr[i]);
        else {
            int j = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[j] = arr[i];
        }
    }
    printf("%d", n - v.size());
    return 0;
}
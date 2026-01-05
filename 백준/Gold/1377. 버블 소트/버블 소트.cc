#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    vector<int> v1, v2;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        v1.push_back(a);
        v2.push_back(a);   
    }
    sort(v2.begin(), v2.end());

    int max_i = 0;
    for(int i=0; i<n; i++) {
        int sorted_i = upper_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() - 1;
        if(i <= sorted_i) continue;

        max_i = max(max_i, i - sorted_i);
    }
    printf("%d", max_i + 1);
    return 0;
}

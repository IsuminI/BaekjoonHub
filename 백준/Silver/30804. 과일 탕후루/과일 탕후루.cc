#include <bits/stdc++.h>
using namespace std;
int n, arr[200001], sum[200001], fruit[10];
set<int> s;
int main() {
    sum[0] = 0;
    scanf("%d", &n);
    int left = 1;
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        s.insert(arr[i]);
        fruit[arr[i]]++;

        if(s.size() <= 2) {
            cnt = max(cnt, i-left+1);
        }
        else {
            while(s.size() > 2) {
                if(!--fruit[arr[left]]) {
                    s.erase(arr[left]);
                }
                left++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}

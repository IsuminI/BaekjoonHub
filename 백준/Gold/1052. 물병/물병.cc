#include <bits/stdc++.h>
using namespace std;
int n, k, arr[65];
int main() {

    scanf("%d %d", &n, &k);

    int value = 0;
    while(1) {
        if((int)pow(2, value) > n) {
            value--;
            break;
        }
        else if((int)pow(2, value) == n) break;
        value++;
    }

    int nn = n;
    int i = value;
    int cnt = 0;
    while(nn != 0) {
        int v = (int)pow(2, i);
        if(nn < v) {
            i--;
            continue;
        }
        arr[i] = 1;
        cnt++;
        i--;
        nn -= v;
    }

    if(cnt <= k) printf("0");
    else {
        int i = 0;
        int sum = 0;
        while(cnt > k) {
            if(arr[i] == 1) {
                sum += (int)pow(2, i);
                arr[i+1]++;
            }
            else if(arr[i] == 2) {
                arr[i+1]++;
                cnt--;
            }
            i++;
        }
        printf("%d", sum);
    }
    return 0;
}
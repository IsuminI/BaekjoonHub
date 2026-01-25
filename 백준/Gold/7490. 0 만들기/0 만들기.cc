#include <bits/stdc++.h>
using namespace std;
int n;
char arr[10];
void dfs(int x) {
    if(x == n) {
        int sum = 1;
        int num = 0;

        int i=1;
        while(i <= n-1) {
            if(arr[i] == '+') {
                num = i+1;
                while(arr[i+1] == ' ') {
                    num *= 10;
                    num += i+2;
                    i++;
                }
                sum += num;
                i++;
            }
            else if(arr[i] == '-') {
                num = i+1;
                while(arr[i+1] == ' ') {
                    num *= 10;
                    num += i+2;
                    i++;
                }
                sum -= num;
                i++;
            }
            else {
                num = 12;
                while(arr[i+1] == ' ') {
                    num *= 10;
                    num += i+2;
                    i++;
                }
                sum = num;
                i++;
            }
        }

        if(sum == 0) {
            for(int i=1; i<=n-1; i++) {
                printf("%d%c", i, arr[i]);
            }
            printf("%d\n", n);
        }
        return;
    }

    arr[x] = ' ';
    dfs(x+1);
    
    arr[x] = '+';
    dfs(x+1);
    
    arr[x] = '-';
    dfs(x+1);
}
int main() {

    int t;
    for(scanf("%d", &t); t--; puts("")) {
        scanf("%d", &n);
        dfs(1);
    }
    return 0;
}
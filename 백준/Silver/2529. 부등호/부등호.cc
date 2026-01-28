#include <bits/stdc++.h>
using namespace std;
int k, dp[10];
int check[10];
char arr[10];
long long int MIN=9999999999, MAX;
int MIN_FLAG, MAX_FLAG;
void dfs(int index, int prev) {
    if(index == k + 1) {
        long long int value = 0;
        for(int i=0; i<=k; i++) {
            value *= 10;
            value += dp[i];
        }
        if(MIN > value) {
            MIN = value;
            if(dp[0] == 0) MIN_FLAG = 1;
            else MIN_FLAG = 0;
        }
        if(MAX < value) {
            MAX = value;
            if(dp[0] == 0) MAX_FLAG = 1;
            else MAX_FLAG = 0;
        }
        return;
    }

    for(int i=0; i<=9; i++) {
        if(!check[i]) {
            if(prev == -1) {
                check[i] = 1;
                dp[index] = i;
                dfs(index+1, i);
            }
            else {
                if(arr[index - 1] == '<' && prev < i) {
                    check[i] = 1;
                    dp[index] = i;
                    dfs(index+1, i);
                } 
                else if(arr[index - 1] == '>' && prev > i) {
                    check[i] = 1;
                    dp[index] = i;
                    dfs(index+1, i);
                }
            }
            check[i] = 0;
        }
    }
}


int main() {
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf(" %c", &arr[i]);
    }
    dfs(0, -1);
    if(MAX_FLAG) printf("0%lld", MAX);
    else printf("%lld", MAX);
    printf("\n");
    if(MIN_FLAG) printf("0%lld", MIN);
    else printf("%lld", MIN);
    return 0;
}
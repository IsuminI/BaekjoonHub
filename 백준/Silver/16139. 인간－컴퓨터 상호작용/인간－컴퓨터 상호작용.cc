#include <bits/stdc++.h>
using namespace std;
char arr[200001];
int q, l, r;
char a;
int dp[26][200001];
int main() {

    scanf("%s", &arr);
    int t = strlen(arr);
    for(int i=0; i<26; i++) {
        for(int j=0; j<t; j++) {
            if(arr[j] - 'a' == i) {
                if(j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i][j-1] + 1;
            }
            else dp[i][j] = dp[i][j-1];
        }
    }

    for(scanf("%d", &q);q--;) {
        scanf(" %c %d %d", &a, &l, &r);

        if(l == 0) {
            printf("%d\n", dp[a-'a'][r]);
        }
        else printf("%d\n", dp[a-'a'][r] - dp[a-'a'][l-1]);
    }
    return 0;
}

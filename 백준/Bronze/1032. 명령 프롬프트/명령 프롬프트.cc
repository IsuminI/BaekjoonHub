#include <bits/stdc++.h>
using namespace std;
int n;
char arr[51][51];
char answer[51];
int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf(" %s", &arr[i]);
    }

    int t = strlen(arr[0]);
    for(int i=0; i<t; i++) {
        int flag = 0;
        for(int j=0; j<n-1; j++) {
            if(arr[j][i] != arr[j+1][i]) flag = 1;
        }
        if(flag) answer[i] = '?';
        else answer[i] = arr[0][i];
    }
    printf("%s", answer);
    return 0;
}
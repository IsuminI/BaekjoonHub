#include <bits/stdc++.h>
using namespace std;
int n,m;
int check(int arr_a[51][51], int arr_b[51][51]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr_a[i][j] != arr_b[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    int a[51][51],b[51][51];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &b[i][j]);
        }
    }

    int cnt = 0;
    for(int i=0; i<n-3+1; i++) {
        for(int j=0; j<m-3+1; j++) {
            if(a[i][j] != b[i][j]) {
                cnt++;
                for(int p=i; p<=i+2; p++) {
                    for(int q=j; q<=j+2; q++) {
                        a[p][q] = !a[p][q];
                    }
                }
            }
        }
    }
    if(check(a, b)) printf("%d", cnt);
    else printf("-1");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, t, x, d, kk;
int arr[200][200];
int check[200][200];

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<t; i++) {
        scanf("%d %d %d", &x, &d, &kk);
        
        for(int j=x; j<=n; j+=x) {
            for(int k=1; k<=m; k++) arr[j][k+m] = arr[j][k];
            if(d == 0) {
                for(int k=m-kk+1, cnt=1; k<=m-kk+1+m-1; k++, cnt++) {
                    arr[j][cnt] = arr[j][k];
                }
            }
            else {
                for(int k=1+kk, cnt=1; k<=1+kk+m-1; k++, cnt++) {
                    arr[j][cnt] = arr[j][k];
                }
            }
        }

        int flag = 0;
        int num = 0;
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                if(k == m) {
                    if(arr[j][k] == arr[j][1]) {
                        if(arr[j][k] != 0) flag = 1;
                        check[j][k] = 1;
                        check[j][1] = 1;
                    }
                }
                else {
                    if(arr[j][k] == arr[j][k+1]) {
                        if(arr[j][k] != 0) flag = 1;
                        check[j][k] = 1;
                        check[j][k+1] = 1;
                    }
                }

                if(j == n) continue;
                else {
                    if(arr[j][k] == arr[j+1][k]) {
                        if(arr[j][k] != 0) flag = 1;
                        check[j][k] = 1;
                        check[j+1][k] = 1;
                    }
                }
            }
        }

        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                if(check[j][k]) {
                    check[j][k] = 0;
                    arr[j][k] = 0;
                }
            }
        }

        if(!flag) {
            int sum = 0;
            int cnt = 0;
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=m; k++) {
                    if(arr[j][k]) cnt++;
                    sum += arr[j][k];
                }
            }
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=m; k++) {
                    if(arr[j][k]) {
                        if(arr[j][k] * cnt < sum) arr[j][k]++;
                        else if(arr[j][k] * cnt > sum) arr[j][k]--;
                    }
                }
            }
        }

    }
    int sum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum += arr[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}

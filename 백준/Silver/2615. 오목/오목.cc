#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[20][20];
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int win = 0;
    int x,y;

    // 가로 정방향
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19-5+1; j++) {
            if(arr[i][j] == 0) continue;
            if(arr[i][j] == 1) {
                if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2] && arr[i][j+2] == arr[i][j+3] && arr[i][j+3] == arr[i][j+4]) {
                    if(j-1 != 0) {
                        if(arr[i][j] == arr[i][j-1]) continue;
                    }
                    if(j+5 != 20) {
                        if(arr[i][j] == arr[i][j+5]) continue;
                    }
                    win = 1;
                    x = i;
                    y = j;
                }
            }
            if(arr[i][j] == 2) {
                if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2] && arr[i][j+2] == arr[i][j+3] && arr[i][j+3] == arr[i][j+4]) {
                    if(j-1 != 0) {
                        if(arr[i][j] == arr[i][j-1]) continue;
                    }
                    if(j+5 != 20) {
                        if(arr[i][j] == arr[i][j+5]) continue;
                    }

                    win = 2;
                    x = i;
                    y = j;
                }
            }
        }
    }

    // 세로 정방향
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19-5+1; j++) {
            if(arr[j][i] == 0) continue;
            if(arr[j][i] == 1) {
                if(arr[j][i] == arr[j+1][i] && arr[j+1][i] == arr[j+2][i] && arr[j+2][i] == arr[j+3][i] && arr[j+3][i] == arr[j+4][i]) {
                    if(j-1 != 0) {
                        if(arr[j][i] == arr[j-1][i]) continue;
                    }
                    if(j+5 != 20) {
                        if(arr[j][i] == arr[j+5][i]) continue;
                    }
                    win = 1;
                    x = j;
                    y = i;
                }
            }
            if(arr[j][i] == 2) {
                if(arr[j][i] == arr[j+1][i] && arr[j+1][i] == arr[j+2][i] && arr[j+2][i] == arr[j+3][i] && arr[j+3][i] == arr[j+4][i]) {
                    if(j-1 != 0) {
                        if(arr[j][i] == arr[j-1][i]) continue;
                    }
                    if(j+5 != 20) {
                        if(arr[j][i] == arr[j+5][i]) continue;
                    }
                    win = 2;
                    x = j;
                    y = i;
                }
            }
        }
    }

    // 대각선 정방향
    for(int i=1; i<=19-5+1; i++) {
        for(int j=1; j<=19-5+1; j++) {
            if(arr[i][j] == 0) continue;
            if(arr[i][j] == 1) {
                if(arr[i][j] == arr[i+1][j+1] && arr[i+1][j+1] == arr[i+2][j+2] && arr[i+2][j+2] == arr[i+3][j+3] && arr[i+3][j+3] == arr[i+4][j+4]) {
                    if(i+5 != 20 && j+5 != 20) {
                        if(arr[i][j] == arr[i+5][j+5]) continue;
                    } 
                    if(i-1 != 0 && j-1 != 0) {
                        if(arr[i][j] == arr[i-1][j-1]) continue;
                    }
                    win = 1;
                    x = i;
                    y = j;
                }
            }
            if(arr[i][j] == 2) {
                if(arr[i][j] == arr[i+1][j+1] && arr[i+1][j+1] == arr[i+2][j+2] && arr[i+2][j+2] == arr[i+3][j+3] && arr[i+3][j+3] == arr[i+4][j+4]) {
                    if(i+5 != 20 && j+5 != 20) {
                        if(arr[i][j] == arr[i+5][j+5]) continue;
                    } 
                    if(i-1 != 0 && j-1 != 0) {
                        if(arr[i][j] == arr[i-1][j-1]) continue;
                    }
                    win = 2;
                    x = i;
                    y = j;
                }
            }
        }
    }

    // 대각선 역방향
    for(int i=1; i<=19-5+1; i++) {
        for(int j=19; j>=5; j--) {
            if(arr[i][j] == 0) continue;
            if(arr[i][j] == 1) {
                if(arr[i][j] == arr[i+1][j-1] && arr[i+1][j-1] == arr[i+2][j-2] && arr[i+2][j-2] == arr[i+3][j-3] && arr[i+3][j-3] == arr[i+4][j-4]) {
                    if(i+5 != 20 && j-5 != 0) {
                        if(arr[i][j] == arr[i+5][j-5]) continue;
                    }
                    if(i-1 != 0 && j+1 != 20) {
                        if(arr[i][j] == arr[i-1][j+1]) continue;
                    }
                    win = 1;
                    x = i+4;
                    y = j-4;
                }
            }
            if(arr[i][j] == 2) {
                if(arr[i][j] == arr[i+1][j-1] && arr[i+1][j-1] == arr[i+2][j-2] && arr[i+2][j-2] == arr[i+3][j-3] && arr[i+3][j-3] == arr[i+4][j-4]) {
                    if(i+5 != 20 && j-5 != 0) {
                        if(arr[i][j] == arr[i+5][j-5]) continue;
                    }
                    if(i-1 != 0 && j+1 != 20) {
                        if(arr[i][j] == arr[i-1][j+1]) continue;
                    }
                    win = 2;
                    x = i+4;
                    y = j-4;
                }
            }
        }
    }
    printf("%d\n", win);
    if(win) {
        printf("%d %d", x, y);
    }
    return 0;
}
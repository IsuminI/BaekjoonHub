#include <bits/stdc++.h>
using namespace std;
char arr[13][7];
int check[13][7];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int Search(int x, int y, char color) {
    if(x < 0 || x >= 12 || y < 0 || y >= 6) return 0;
    if(arr[x][y] != color) return 0;
    if(check[x][y]) return 0;
    check[x][y] = 1;
    
    int sum = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += Search(nx, ny, color);
    }
    return sum + 1;
}

void Delete(int x, int y, int color) {
    if(x < 0 || x >= 12 || y < 0 || y >= 6) return ;
    if(arr[x][y] != color) return ;
    arr[x][y] = '.';
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Delete(nx, ny, color);
    }
}

void Down() {
    for(int j=0; j<6; j++) {
        int locate = 11;
        for(int i=11; i>=0; i--) {
            if(arr[i][j] != '.') {
                swap(arr[i][j], arr[locate--][j]);
            }
        }
    }
}

void Print() {
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            printf("%c", arr[i][j]);
        }
        puts("");
    }
    printf("\n\n");
}
int main() {
    for(int i=0; i<12; i++) {
        scanf("%s", &arr[i]);
    }

    int cnt = 0;
    while(1){
        int flag = 0;
        for(int i=11; i>=0; i--) {
            for(int j=0; j<6; j++) {
                if(arr[i][j] == '.') continue;

                char cur_color = arr[i][j];
                int cur_cnt = Search(i, j, cur_color);

                if(cur_cnt < 4) continue;
                flag = 1;

                Delete(i, j, cur_color);
            }
        }
        Down();
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                check[i][j] = 0;
            }
        }
        if(!flag) break;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}

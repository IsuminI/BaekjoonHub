#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x,y;
}st;
int main() {
    int n;
    char arr[7][7];
    vector<st> v;
    vector<st> tt;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'X') v.push_back({i, j});
            else if(arr[i][j] == 'T') tt.push_back({i, j});
        }
    }

    int t = v.size();
    int tts = tt.size();
    for(int i=0; i<t; i++) {
        for(int j=i+1; j<t; j++) {
            for(int k=j+1; k<t; k++) {
                st x = v[i];
                st y = v[j];
                st z = v[k];
                arr[x.x][x.y] = 'O';
                arr[y.x][y.y] = 'O';
                arr[z.x][z.y] = 'O';
                // printf("%d %d | %d %d | %d %d\n", x.x, x.y, y.x, y.y, z.x, z.y);

                int flag = 0;
                for(int p=0; p<tts; p++) {
                    if(flag) break;
                    int px, py;

                    px = tt[p].x;
                    py = tt[p].y;
                    while(px >= 0) {
                        if(arr[px][py] == 'S') {
                            flag = 1;
                            break;
                        }
                        else if(arr[px][py] == 'O') break;
                        px--;
                    }

                    px = tt[p].x;
                    py = tt[p].y;
                    while(px < n) {
                        if(arr[px][py] == 'S') {
                            flag = 1;
                            break;
                        }
                        else if(arr[px][py] == 'O') break;
                        px++;
                    }
                    

                    px = tt[p].x;
                    py = tt[p].y;
                    while(py >= 0) {
                        if(arr[px][py] == 'S') {
                            flag = 1;
                            break;
                        }
                        else if(arr[px][py] == 'O') break;
                        py--;
                    }

                    px = tt[p].x;
                    py = tt[p].y;
                    while(py < n) {
                        if(arr[px][py] == 'S') {
                            flag = 1;
                            break;
                        }
                        else if(arr[px][py] == 'O') break;
                        py++;
                    }
                    
                }
                if(!flag) {
                    printf("YES");
                    return 0;
                }
                arr[x.x][x.y] = 'X';
                arr[y.x][y.y] = 'X';
                arr[z.x][z.y] = 'X';
            }
        }
    }
    printf("NO");
    return 0;
}
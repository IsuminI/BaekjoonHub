#include <bits/stdc++.h>
using namespace std;
char arr[51];
int cnt;
int check(int start, int end) {
    for(int i=0; i < ((end - start + 1) / 2); i++) {
        if(arr[start + i] != arr[end-i]) return 0;
    }
    return 1;
}
int main() {

    scanf("%s", arr);
    int t = strlen(arr);
    for(int i=0; i<t; i++) {
        if(check(i, t-1)) {
            printf("%d", t+i);
            break;
        }
    }
    return 0;
}

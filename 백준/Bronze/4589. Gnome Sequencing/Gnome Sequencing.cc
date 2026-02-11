#include <bits/stdc++.h>
using namespace std;
int t, arr[101];
int main() {
    printf("Gnomes:\n");
    scanf("%d", &t);
    for(int k=0; k<t; k++) {
        for(int i=0; i<3; i++) {
            scanf("%d", &arr[i]);
        }
        int lflag = 0;
        for(int i=0; i<2; i++) {
            if(arr[i] > arr[i+1]) lflag = 1;
        }
        if(!lflag) {
            printf("Ordered\n");
        }
        else {
            int rflag = 0;
            for(int i=0; i<2; i++) {
                if(arr[i] < arr[i+1]) rflag = 1;
            }
            if(!rflag) {
                printf("Ordered\n");
            }
            else {
                printf("Unordered\n");
            }
        }
    }
    return 0;
}


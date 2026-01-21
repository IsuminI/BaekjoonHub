#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum, a, b;
int x[101], y[101];
int main() {

    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    scanf("%d %d", &a, &b);

    for(int i=0; i<k; i++) {
        if(a == 1) {
            if(x[i] == 1) sum += abs(y[i] - b);
            else if(x[i] == 2) sum += min(y[i] + b, n-y[i] + n-b) + m;
            else if(x[i] == 3) sum += b + y[i];
            else sum += n-b + y[i];
        }
        else if(a == 2) {
            if(x[i] == 2) sum += abs(y[i] - b);
            else if(x[i] == 1) sum += min(y[i] + b, n-y[i] + n-b) + m;
            else if(x[i] == 3) sum += b + m-y[i];
            else sum += n-b + m-y[i];
        }
        else if(a == 3) {
            if(x[i] == 3) sum += abs(y[i] - b);
            else if(x[i] == 4) sum += min(y[i] + b, m-y[i] + m-b) + n;
            else if(x[i] == 1) sum += b + y[i];
            else sum += n-b + y[i];
        }
        else {
            if(x[i] == 4) sum += abs(y[i] - b);
            else if(x[i] == 3) sum += min(y[i] + b, m-y[i] + m-b) + n;
            else if(x[i] == 1) sum += b + n-y[i];
            else sum += n-b + m-y[i];            
        }
    }
    printf("%d", sum);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int t,n,a;

    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;

    for(scanf("%lld", &t);t--;) {

        scanf("%lld", &n);

        for(int i=0; i<n; i++) {

            scanf("%lld", &a);

            pq.push(a);

        }

        long long int sum=0;

        while(1) {

            if(pq.size() == 1) break;

            long long int p = pq.top();

            pq.pop();

            long long int q = pq.top();

            pq.pop();

            pq.push(p+q);

            sum += p+q;

        }

        printf("%lld\n", sum);

        pq.pop();

        

    }

    return 0;

}
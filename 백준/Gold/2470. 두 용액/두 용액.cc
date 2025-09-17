#include <bits/stdc++.h>
using namespace std;
int n, arr[100001], a=0, b=2000000001;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++) {
        int target = -arr[i];
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid] == target) {
                a = arr[i];
                b = arr[mid];
                break;
            }
            else if(arr[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if(left == n) {
            if(right == i) right--;
            if(abs(arr[i] + arr[right]) < abs(a+b)) {
                 a = arr[i];
                 b = arr[right];
            }
        }
        else if(right == -1) {
            if(left == i) left++;
            if(abs(arr[i] + arr[left]) < abs(a+b)) {
                 a = arr[i];
                 b = arr[left];
            }
        }
        else {
            if(right == i) right++;
            if(abs(arr[i] + arr[right]) < abs(a+b)) {
                 a = arr[i];
                 b = arr[right];
            }
            if(left == i) left--;
            if(abs(arr[i] + arr[left]) < abs(a+b)) {
                 a = arr[i];
                 b = arr[left];
            }
        }
    }
    printf("%d %d", a<b?a:b, a<b?b:a);
    return 0;
}
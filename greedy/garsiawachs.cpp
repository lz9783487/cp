// POJ 1738

#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = (int) 5e4 + 5;
int a[N];
int n;
int main() {
    while (scanf("%d", &n), n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        if (n == 1) {
            puts("0");
            continue;
        }
        int ans = 0;
        int left = 1;
        while (left < n - 1) {
            int k;
            for (k = left; k < n - 1; ++k) {
                if (a[k] <= a[k + 2]) {
                    a[k + 1] += a[k];
                    ans += a[k + 1];
                    for (int j = k; j > left; --j) {
                        a[j] = a[j - 1];
                    }
                    ++left;
                    int j = k + 1;
                    while (a[j] > a[j - 1] && j > left) {
                        swap(a[j], a[j - 1]);
                        --j;
                    }
                    break;
                }
            }
            if (k == n - 1) {
                a[n - 1] += a[n];
                ans += a[--n];
            }
        }
        ans += a[n - 1] + a[n];
        printf("%d\n", ans);
    }
    return 0;
}
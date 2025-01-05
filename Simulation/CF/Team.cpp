// https://codeforces.com/problemset/problem/231/A

#include <cstdio>
#include <vector>
#include <array>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p, v, t;
        scanf("%d%d%d", &p, &v, &t);
        if (p + v + t > 1) {
            ans++;
        }
    }

    printf("%d", ans);
}
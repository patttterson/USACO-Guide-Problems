// https://usaco.org/index.php?cpid=567&page=viewproblem2

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);
    
    vector<bool> fence(100, false);
    for (int i = a; i < b; i++) {
        fence[i] = true;
    }
    for (int i = c; i < d; i++) {
        fence[i] = true;
    }

    printf("%d", count(fence.begin(), fence.end(), true));
}
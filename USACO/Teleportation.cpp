// http://www.usaco.org/index.php?page=viewproblem2&cpid=807

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int tp = 0;
    if (abs(a-x) < abs(a-y)) {
        tp = abs(a-x) + abs(b-y);
    } else {
        tp = abs(a-y) + abs(b-x);
    }

    printf("%d", min(tp,abs(a-b)));
}
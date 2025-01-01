// https://usaco.org/index.php?page=viewproblem2&cpid=855

#include <cstdio>
#include <utility>
using namespace std;

void pour(int &c1, int &b1, int &c2, int &b2) {
    if (b1 + b2 > c2) {
        // if pouring maxes out capacity
        b1 -= c2 - b2;
        b2 = c2;
    } else {
        b2 += b1;
        b1 = 0;
    }
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    pair<int, int> buckets[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &buckets[i].first, &buckets[i].second);
    }

    for (int i = 0; i < 100; i++) {
        int from = i % 3;
        int to = (i + 1) % 3;
        pour(buckets[from].first, buckets[from].second, buckets[to].first, buckets[to].second);
    }

    for (int i = 0; i < 3; i++) {
        printf("%d\n", buckets[i].second);
    }
}
// https://usaco.org/index.php?page=viewproblem2&cpid=591
// Intended solution, but not solved independently

#include <cstdio>
#include <utility>
using namespace std;

pair<int, int> ppl[4];
int discrepancy[4];
int promoted[3]; // gold to plat, silver to gold, bronze to silver

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    for (int i = 0; i < 4; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ppl[i] = {a, b};
    }

    promoted[0] = ppl[3].second - ppl[3].first;
    promoted[1] = ppl[2].second - ppl[2].first + promoted[0];
    promoted[2] = ppl[1].second - ppl[1].first + promoted[1]; 

    printf("%d\n%d\n%d", promoted[2], promoted[1], promoted[0]);
}
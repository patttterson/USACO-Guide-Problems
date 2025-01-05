// https://usaco.org/index.php?page=viewproblem2&cpid=891
// Intended solution, inefficient

#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int, int, int> game[100];

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, guess;
        scanf("%d%d%d", &a, &b, &guess);
        game[i] = tie(a, b, guess);
    }

    int scores[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++) {
        int score = 0;
        bool shells[3] = {false, false, false};
        shells[i] = true;
        for (int j = 0; j < n; j++) {
            bool tmp;
            tmp = shells[get<0>(game[j]) - 1];
            shells[get<0>(game[j]) - 1] = shells[get<1>(game[j]) - 1];
            shells[get<1>(game[j]) - 1] = tmp;
            if (shells[get<2>(game[j]) - 1]) { score++; }
        }

        scores[i] = score;
    }

    printf("%d", *max_element(scores, scores + 3));
}
// https://usaco.org/index.php?page=viewproblem2&cpid=939
// Unintended solution and/or not finished

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char grid[10][10];
bool visited[10][10];

void floodfill(int x, int y, int steps) {
    if (x < 0 || x > 9 || y < 0 || y > 9 || grid[y][x] == 'R' || visited[y][x]) {
        return;
    }

    if (grid[y][x] == 'B') {
        cout << --steps << endl;
        exit(0);
    }

    visited[y][x] = true;

    floodfill(x, y + 1, steps + 1);
    floodfill(x, y - 1, steps + 1);
    floodfill(x + 1, y, steps + 1);
    floodfill(x - 1, y, steps + 1);
}

int main() {
    // freopen("bucket.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_n(visited[0], 100, false);
    fill(visited[0], visited[10], false);

    int x, y;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L') { x = j, y = i; }
        }
    }

    floodfill(x, y, 0);
}
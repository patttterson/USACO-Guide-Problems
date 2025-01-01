// https://usaco.org/index.php?page=viewproblem2&cpid=665

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        string line;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            for(int l = 0; l < k; l++) { line += c; }
        }
        
        for (int l = 0; l < k; l++) { cout << line << endl; }
    }
}
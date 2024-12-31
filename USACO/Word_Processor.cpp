// https://usaco.org/index.php?page=viewproblem2&cpid=987

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string essay[100];

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> essay[i];
    }

    string line = "";
    int line_length = 0;
    for (int i = 0; i < n; i++) {
        if (line_length + essay[i].length() > k) {
            line.pop_back();
            cout << line << "\n";
            line_length = 0;
            line = "";
            i--;
        } else {
            line += essay[i] + " ";
            line_length += essay[i].length();
        }
    }
    line.pop_back();
    cout << line << "\n";
}
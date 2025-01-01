// https://usaco.org/index.php?page=viewproblem2&cpid=568

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int segments[100]; // length, speeed
int speeds[100];

int main() {
    setIO("speeding");
    int n, m;
    cin >> n >> m;

    int last = 0;
    for (int i = 0; i < n; i++) {
        int l, sp;
        cin >> l >> sp;
        for (int j = last; j < last + l; j++) {
            segments[j] = sp;
        }
        
        last += l;
    }

    last = 0;
    for (int i = 0; i < m; i++) {
        int l, sp;
        cin >> l >> sp;
        for (int j = last; j < last + l; j++) {
            speeds[j] = sp;
        }
        
        last += l;
    }

    int max_over = 0;
    for (int i = 0; i < 100; i++) {
        max_over = max(max_over, speeds[i] - segments[i]);
    }

    cout << max_over << endl;
}
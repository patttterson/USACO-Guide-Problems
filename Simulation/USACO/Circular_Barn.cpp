// https://usaco.org/index.php?page=viewproblem2&cpid=616

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

int rooms[1000];

int main() {
    setIO("cbarn");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    int ans = 99999999;
    for (int i = 0; i < n; i++) {
        int total_moved = 0;
        for (int j = 0; j < n; j++) {
            total_moved += rooms[(i + j) % n] * j;
        }

        ans = min(ans, total_moved);
    }

    cout << ans << endl;
}
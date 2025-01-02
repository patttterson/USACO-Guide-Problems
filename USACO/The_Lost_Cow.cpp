// https://usaco.org/index.php?page=viewproblem2&cpid=735

#include <iostream>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("lostcow");

    int x, y;
    cin >> x >> y;

    int ans = 0;
    int pos = x;
    int step = 1;
    int direction = 1;

    while (true) {
        int next_pos = x + step * direction;
        if ((direction == 1 && pos <= y && y <= next_pos) || (direction == -1 && pos >= y && y >= next_pos)) {
            ans += abs(pos - y);
            cout << ans << endl;
            return 0;
        }

        ans += abs(next_pos - pos);
        pos = next_pos;
        step *= 2;
        direction *= -1;
    }
}
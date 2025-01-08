// 

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
    setIO("pails");

    int x, y, m;
    cin >> x >> y >> m;

    int total = 0;
    int max_x = 0;
    while (total < m) {
        total += x;
        max_x++;
    }

    max_x--;

    total = 0;
    int max_y = 0;
    while (total < m) {
        total += y;
        max_y++;
    }

    max_y--;

    int max_milk = 0;
    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            int milk = i*x + j*y;
            if (milk <= m) {
                max_milk = max(max_milk, milk);
            }
        }
    }

    cout << max_milk << endl;
}
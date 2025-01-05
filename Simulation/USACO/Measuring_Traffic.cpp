// https://usaco.org/index.php?page=viewproblem2&cpid=917

#include <iostream>
#include <vector>
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

int segments[100][3];

int main() {
    setIO("traffic");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string d;
        int state;
        cin >> d >> segments[i][1] >> segments[i][2];
        if (d == "none") { state = 0; }
        else if (d == "on") { state = 1; }
        else if (d == "off") { state = 2; }

        segments[i][0] = state;
    }

    int min_cars = 0;
    int max_cars = 10000000;
    for (int i = n - 1; i >= 0; i--) {
        if (segments[i][0] == 0) {
            min_cars = max(min_cars, segments[i][1]);
            max_cars = min(max_cars, segments[i][2]);
        } else if (segments[i][0] == 2) {
            min_cars += segments[i][1];
            max_cars += segments[i][2];
        } else if (segments[i][0] == 1) {
            min_cars -= segments[i][2];
            max_cars -= segments[i][1];
            min_cars = max(0, min_cars);
        }
    }

    cout << min_cars << " " << max_cars << endl;

    min_cars = 0;
    max_cars = 10000000;
    for (int i = 0; i < n; i++) {
        if (segments[i][0] == 0) {
            min_cars = max(min_cars, segments[i][1]);
            max_cars = min(max_cars, segments[i][2]);
        } else if (segments[i][0] == 1) {
            min_cars += segments[i][1];
            max_cars += segments[i][2];
        } else if (segments[i][0] == 2) {
            min_cars -= segments[i][2];
            max_cars -= segments[i][1];
            min_cars = max(0, min_cars);
        }
    }

    cout << min_cars << " " << max_cars << endl;
}
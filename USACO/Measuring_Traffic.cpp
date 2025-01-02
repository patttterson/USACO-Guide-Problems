// https://usaco.org/index.php?page=viewproblem2&cpid=917
// Unintended solution and/or not finished
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

    int first = -1; // the first section without a ramp
    for (int i = 0; i < n; i++) {
        string d;
        int state;
        cin >> d >> segments[i][1] >> segments[i][2];
        if (d == "none") {
            state = 0;
            if (first < 0) {
                first = i;
            }
        }
        else if (d == "on") { state = 1; }
        else if (d == "off") { state = 2; }

        segments[i][0] = state;
    }

    int s;
    int min_cars = segments[first][1], max_cars = segments[first][2];
    for (int i = first; i < n; i++) {
        if (segments[i][0]) {
            s = i;
            break;
        }
        min_cars = max(min_cars, segments[i][1]);
        max_cars = min(max_cars, segments[i][2]);
    }

    int initial_min = min_cars, initial_max = max_cars;
    for (int i = first - 1; i > -1; i--) {
        if (segments[i][0] == 1) {
            initial_min -= segments[i][1];
            initial_max -= segments[i][2];
        } else {
            initial_min += segments[i][1];
            initial_max += segments[i][2];
        }
    }

    cout << initial_min << " " << initial_max << endl;

    for (int i = s; i < n; i++) {
        switch (segments[i][0]) {
            case 0:
                min_cars = max(min_cars, segments[i][1]);
                max_cars = min(max_cars, segments[i][2]);
                break;
            case 1:
                min_cars += segments[i][1];
                max_cars += segments[i][2];
                break;
            case 2:
                min_cars -= segments[i][2];
                max_cars -= segments[i][1];
                break;
        }
    }

    cout << min_cars << " " << max_cars << endl;
}
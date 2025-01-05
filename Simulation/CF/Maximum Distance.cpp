// https://codeforces.com/gym/102951/problem/A

#include <iostream>
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

int x[5000];
int y[5000];

int main() {
    setIO();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_dist = max(max_dist, abs(x[i] - x[j])*abs(x[i] - x[j]) + abs(y[i] - y[j])*abs(y[i] - y[j]));
        }
    }

    cout << max_dist << endl;
}
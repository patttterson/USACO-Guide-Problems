// https://usaco.org/index.php?page=viewproblem2&cpid=760

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

int main() {
    setIO("shuffle");

    int n;
    cin >> n;

    int shuffle[100] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> shuffle[i];
    }

    int cows[100] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < 3; i++) {
        int new_cows[100] = { 0 };
        for (int j = 0; j < n; j++) {
            int prev = distance(begin(shuffle), find(begin(shuffle), end(shuffle), j+1));
            new_cows[prev] = cows[j];
        }

        copy(begin(new_cows), end(new_cows), begin(cows));
    }

    for (int i = 0; i < n; i++) { cout << cows[i] << endl; }
}
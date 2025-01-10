// https://usaco.org/index.php?page=viewproblem2&cpid=1228
// taken from https://usaco.guide/problems/usaco-1228-counting-liars/solution
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
    setIO();
	
	int n;
	cin >> n;

	vector<pair<int, char>> cows(n);
	for (int i = 0; i < n; i++) {
		// The position is read into .first for sorting.
		cin >> cows[i].second >> cows[i].first;
	}

	sort(cows.begin(), cows.end());

	vector<int> lying_left(n);
	for (int i = 1; i < n; i++) {
		lying_left[i] += lying_left[i - 1];

		if (cows[i - 1].second == 'L') {
			lying_left[i]++;
		}
	}

	vector<int> lying_right(n);
	for (int i = n - 2; i >= 0; i--) {
		lying_right[i] += lying_right[i + 1];

		if (cows[i + 1].second == 'G') { lying_right[i]++; }
	}

	int min_liars = n;
	for (int i = 0; i < n; i++) {
		min_liars = min(min_liars, lying_left[i] + lying_right[i]);
	}

	cout << min_liars << endl;
}
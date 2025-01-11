// https://usaco.org/index.php?page=viewproblem2&cpid=619
// same solution as https://usaco.org/index.php?page=viewproblem2&cpid=617
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
    setIO("balancing");

	int cow_num;
	cin >> cow_num;

	vector<int> x(cow_num);
	vector<int> y(cow_num);
	set<int> v_fence;
	set<int> h_fence;

	for (int c = 0; c < cow_num; c++) {
		cin >> x[c] >> y[c];
		v_fence.insert(x[c] + 1);
		h_fence.insert(y[c] + 1);
	}

	int min_imbalance = cow_num;
	for (int v : v_fence) {
		for (int h : h_fence) {
			int top_left = 0;
			int top_right = 0;
			int bottom_left = 0;
			int bottom_right = 0;

			for (int c = 0; c < cow_num; c++) {
				if (x[c] < v && y[c] > h) {
					top_left++;
				} else if (x[c] > v && y[c] > h) {
					top_right++;
				} else if (x[c] < v && y[c] < h) {
					bottom_left++;
				} else if (x[c] > v && y[c] < h) {
					bottom_right++;
				}
			}

			min_imbalance = min(min_imbalance,
			                    max({top_left, top_right, bottom_left, bottom_right}));
		}
	}

	cout << min_imbalance << endl;
}
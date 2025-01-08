// https://usaco.org/index.php?page=viewproblem2&cpid=639

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
    setIO("diamond");

	int n, k;
	cin >> n >> k;

	int max_size = 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_size = max(max_size, arr[i]);
	}

	sort(arr, arr+n);

	int ans = 0;
	for (int i = 0; i < max_size; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] >= i && arr[j] <= i+k) {
				count++;
			}
		}

		ans = max(ans, count);
	}

	cout << ans << endl;
}
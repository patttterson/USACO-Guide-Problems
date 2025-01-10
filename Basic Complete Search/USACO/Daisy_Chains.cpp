// https://usaco.org/index.php?page=viewproblem2&cpid=1060

#include <iostream>
#include <algorithm>
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

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int avg = 0;
            for (int k = i; k <= j; k++) {
                avg += arr[k];
            }

            if (avg % ((j+1) - i) != 0) {
                continue;
            }

            avg /= (j+1) - i;

            if (find(arr+i, arr+j+1, avg) != arr+j+1) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
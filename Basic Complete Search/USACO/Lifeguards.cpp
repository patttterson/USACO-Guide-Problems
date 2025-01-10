// https://usaco.org/index.php?page=viewproblem2&cpid=784

#include <iostream>
#include <vector>
#include <utility>
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
    setIO("lifeguards");

    int n;
    cin >> n;

    vector<pair<int, int>> lifeguards(n);
    for (int i = 0; i < n; i++) {
        cin >> lifeguards[i].first >> lifeguards[i].second;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> remaining = lifeguards;
        remaining.erase(remaining.begin() + i);

        int count = 0;
        for (int j = 0; j < 1000; j++) {
            bool is_guarded = false;
            for (int k = 0; k < remaining.size(); k++) {
                if (j >= remaining[k].first && j < remaining[k].second) {
                    is_guarded = true;
                    break;
                }
            }

            if (is_guarded) {
                count++;
            }
        }

        ans = max(ans, count);
    }

    cout << ans << endl;
}
// https://usaco.org/index.php?page=viewproblem2&cpid=856

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

vector<vector<int>> cows;

int main() {
    setIO("blist");

    int n;
    cin >> n;

    int last_cow = 0;
    for (int i = 0; i < n; i++) {
        int s, t, b;
        cin >> s >> t >> b;

        last_cow = max(last_cow, t);

        cows.push_back({s, t, b});
    }

    sort(cows.begin(), cows.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });

    int ans = 0;
    int current = 0;
    for (int i = 1; i <= last_cow; i++) { // current time
        for (int j = 0; j < n; j++) {
            if (cows[j][0] == i) {
                current += cows[j][2];
            } 
            
            if (cows[j][1] == i) {
                current -= cows[j][2];
            }
        }

        ans = max(ans, current);
    }

    cout << ans << endl;
}
// https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <iostream>
#include <unordered_set>
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
    setIO("cownomics");

    int n, m;
    cin >> n >> m;

    char spotted[n][m], plain[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotted[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        unordered_set<char> spotted_g;
        unordered_set<char> plain_g;
        unordered_set<char> combined_g;
        for (int j = 0; j < n; j++) {
            spotted_g.insert(spotted[j][i]);
            plain_g.insert(plain[j][i]);
        }

        bool stop = false;
        for (const auto& s : spotted_g) {
            for (const auto& p : plain_g) {
                if (p == s) { stop = true; }
            }

            if (stop) { break; }
        }

        if (!stop) {
            ans++;
        }
    }

    cout << ans << endl;
}
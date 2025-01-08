// https://usaco.org/index.php?page=viewproblem2&cpid=963

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<pair<int, int>> possible_pairs;

int main() {
    setIO("gymnastics");

    int k, n;
    cin >> k >> n;

    int rankings[k][n];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rankings[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { continue; }
            possible_pairs.push_back({rankings[0][i], rankings[0][j]});
        }
    }

    for (int i = 0; i < k; i++) {
        for (int c = 0; c < n; c++) {
            for (int j = 0; j < possible_pairs.size(); j++) {
                if (distance(rankings[i], find(rankings[i], rankings[i] + n, possible_pairs[j].first)) > distance(rankings[i], find(rankings[i], rankings[i] + n, possible_pairs[j].second))) {
                    possible_pairs.erase(possible_pairs.begin() + j);   
                }
            }
        }
    }

    cout << possible_pairs.size() << endl;
}
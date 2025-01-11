// 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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

struct Shake {
	int t, x, y;
	bool operator<(const Shake &tmp) { return t < tmp.t; }
};

int n, t;

vector<Shake> shakes;
vector<bool> cows_infected;

bool is_consistent (int p_0, int k) {
    vector<bool> tmp_infected(n);
    vector<int> num_shakes(n);
    tmp_infected[p_0] = true;
    for (Shake sh : shakes) {
        if (tmp_infected[sh.x]) { num_shakes[sh.x]++; }
        if (tmp_infected[sh.y]) { num_shakes[sh.y]++; }
        if (num_shakes[sh.x] <= k && tmp_infected[sh.x]) {
            tmp_infected[sh.y] = true;
        }
        if (num_shakes[sh.y] <= k && tmp_infected[sh.y]) {
            tmp_infected[sh.x] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tmp_infected[i] != cows_infected[i]) { return false; }
    }
    return true;
};

int main() {
	setIO("tracing");
	string state;
	cin >> n >> t >> state;
	unordered_set<int> possible_patient;

    shakes.resize(t);
    cows_infected.resize(n);

	int min_k = t, max_k = -1;

	for (int i = 0; i < n; i++) { cows_infected[i] = (state[i] == '1'); }

	for (Shake &sh : shakes) {
		cin >> sh.t >> sh.x >> sh.y;
		sh.t--, sh.x--, sh.y--;
	}
	sort(shakes.begin(), shakes.end());

	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= t; k++) {
			if (is_consistent(i, k)) {
				possible_patient.insert(i);
				min_k = min(min_k, k);
				max_k = max(max_k, k);
			}
		}
	}

	cout << possible_patient.size() << " " << min_k << " " << (max_k == t ? "Infinity" : to_string(max_k)) << endl;
}
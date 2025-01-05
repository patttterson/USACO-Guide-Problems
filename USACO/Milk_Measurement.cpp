// https://usaco.org/index.php?page=viewproblem2&cpid=761

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
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

vector<tuple<int, int, int>> milk_log;

bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    setIO("measurement");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        string name;
        cin >> a >> name >> c;

        if (name == "Bessie") {
            b = 0;
        } else if (name == "Elsie") {
            b = 1;
        } else {
            b = 2;
        }

        milk_log.push_back({a, b, c});
    }

    sort(milk_log.begin(), milk_log.end(), comp);

    int ans = 0;
    unordered_set<int> on_display;
    int cows[3] = {7, 7, 7}; // bessie = 0, elsie = 1, mildred = 2
    for (int i = 0; i < n; i++) {
        cows[get<1>(milk_log[i])] += get<2>(milk_log[i]);

        int max_milk = max({cows[0], cows[1], cows[2]});
        unordered_set<int> new_display;
        for (int j = 0; j < 3; j++) {
            if (cows[j] == max_milk) {
                new_display.insert(j);
            }
        }

        if (new_display != on_display) {
            ans++;
        }

        on_display = new_display;
    }

    cout << ans << endl;
}
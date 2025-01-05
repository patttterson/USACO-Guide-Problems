// https://usaco.org/index.php?page=viewproblem2&cpid=1061

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Cow {
    int x, y;
    int index;
};

int main() {
    setIO();

    int n;
    cin >> n;

    vector<Cow> north_cows;
    vector<Cow> east_cows;

    for (int i = 0; i < n; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'N') {
            north_cows.push_back({x, y, i});
        } else {
            east_cows.push_back({x, y, i});
        }
    }

    sort(north_cows.begin(), north_cows.end(), [&](const Cow &c1, const Cow &c2) {return c1.x < c2.x;});
    sort(east_cows.begin(), east_cows.end(), [&](const Cow &c1, const Cow &c2) {return c1.y < c2.y;});

    vector<int> stop_pos(n, -1);
    for (auto &ncow : north_cows) {
        for (auto &ecow : east_cows) {
            if (ncow.x < ecow.x || ncow.y > ecow.y) {
                continue;
            }

            int north_dist = ecow.y - ncow.y;
            int east_dist = ncow.x - ecow.x;

            if (stop_pos[ecow.index] == -1) {
                if (north_dist < east_dist) {
                    stop_pos[ecow.index] = ncow.x;
                }  

                if (north_dist > east_dist) {
                    stop_pos[ncow.index] = ecow.y;
                    break;
                }
            }
        }
    }

    vector<int> ans(n, -1);
    for (auto &ncow : north_cows) {
        if (stop_pos[ncow.index] != -1) {
            ans[ncow.index] = stop_pos[ncow.index] - ncow.y;
        }
    }

    for (auto &ecow : east_cows) {
        if (stop_pos[ecow.index] != -1) {
            ans[ecow.index] = stop_pos[ecow.index] - ecow.x;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (ans[i] == -1 ? "Infinity" : to_string(ans[i])) << endl; 
    }
}
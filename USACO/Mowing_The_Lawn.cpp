// https://usaco.org/index.php?page=viewproblem2&cpid=593

#include <iostream>
#include <utility>
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

int lawn[2000][2000];
pair<int, int> moves[100];

int dx[4] = {0, 1, 0, -1}; // N = 0, E = 1, S = 2, W = 3
int dy[4] = {-1, 0, 1, 0};

int main() {
    setIO("mowing");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> moves[i].second;
        moves[i].first = (c == 'N' ? 0 : (c == 'E' ? 1 : (c == 'S' ? 2 : 3))); // N = 0, E = 1, S = 2, W = 3
    }

    int regrow_time = 99999999;
    int x = 1000, y = 1000, t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < moves[i].second; j++) {
            x += dx[moves[i].first];
            y += dy[moves[i].first];

            if (lawn[y][x] != 0) {
                regrow_time = min(regrow_time, t - lawn[y][x] + 1);
            }

            t++;
            lawn[y][x] = t;
        }
    }

    if (regrow_time == 99999999) {
        cout << -1 << endl;
    } else {
        cout << regrow_time << endl;
    }

    /*
    for (int i = 980; i < 1020; i++) {
        for (int j = 980; j < 1020; j++) {
            if (lawn[i][j] < 10) {
                cout << lawn[i][j] << "  ";
            } else {
                cout << lawn[i][j] << " ";
            }
        }
        cout << endl;
    }
    */
}
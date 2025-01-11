// https://usaco.org/index.php?page=viewproblem2&cpid=640

#include <iostream>
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

int n;
bool pieces[11][8][8];
vector<int> s[11];

bool check(int piece, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && pieces[piece][x][y];
}

int main() {
	setIO("bcs");
    
	int k;
	cin >> n >> k;
	char c;
	int left, right, top, bottom;
	for (int i = 0; i <= k; i++) {
		left = n - 1;
		right = 0;
		top = n - 1;
		bottom = 0;
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				cin >> c;
				pieces[i][j][l] = (c == '#');
				if (pieces[i][j][l]) {
					bottom = max(bottom, j);
					top = min(top, j);
					right = max(right, l);
					left = min(left, l);
				}
			}
		}
		s[i] = {left, right, top, bottom};
	}

	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			for (int idx = s[i][3] - n + 1; idx <= s[i][2]; idx++) {
				for (int idy = s[i][1] - n + 1; idy <= s[i][0]; idy++) {
					for (int jdx = s[j][3] - n + 1; jdx <= s[j][2]; jdx++) {
						for (int jdy = s[j][1] - n + 1; jdy <= s[j][0]; jdy++) {
							bool good = true;
							for (int x = 0; x < n; x++) {
								for (int y = 0; y < n; y++) {
									bool i_piece = check(i, x + idx, y + idy);
									bool j_piece = check(j, x + jdx, y + jdy);
									if (i_piece && j_piece) {
										good = false;
										break;
									}
									if (pieces[0][x][y] != (i_piece || j_piece)) {
										good = false;
										break;
									}
								}
								if (!good) { break; }
							}
							if (good) {
								cout << i << " " << j << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
}
// https://usaco.org/index.php?page=viewproblem2&cpid=712

#include <iostream>
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
    setIO("circlecross");

	string crossings;
	cin >> crossings;

	int crossing_pairs = 0;
	for (int a = 0; a < crossings.size(); a++) {
		for (int b = a + 1; b < crossings.size(); b++) {
			for (int c = b + 1; c < crossings.size(); c++) {
				for (int d = c + 1; d < crossings.size(); d++) {
					crossing_pairs += (crossings[a] == crossings[c] && crossings[b] == crossings[d]);
				}
			}
		}
	}

	cout << crossing_pairs << endl;
}
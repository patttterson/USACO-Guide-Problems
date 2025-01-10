// https://usaco.org/index.php?page=viewproblem2&cpid=893

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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

vector<string> animals[100];

int main() {
    setIO("guess");

    int n;
    cin >> n;

    string w;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> w >> m;
        for (int j = 0; j < m; j++) {
            cin >> w;
            animals[i].push_back(w);
        }
    }

    int largest = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            unordered_set<string> s;
            for (int k = 0; k < animals[i].size(); k++) {
                s.insert(animals[i][k]);
            }

            for (int k = 0; k < animals[j].size(); k++) {
                if (s.find(animals[j][k]) != s.end()) {
                    count++;
                }
            }
            largest = max(largest, count);
        }
    }

    cout << largest + 1 << endl;
}
// https://usaco.org/index.php?page=viewproblem2&cpid=664

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
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

string alphabet = "abcdefghijklmnopqrstuvwxyz";
vector<vector<string>> blocks;
int ans[26];

int main() {
    setIO("blocks");

    int n;
    cin >> n;

    int first = 0, second = 0;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        blocks.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        int freq[26] = {0};
        int freq_2[26] = {0};
        for (char& c : blocks[i][0]) {
            freq[alphabet.find(c)]++;
        }

        for (char& c : blocks[i][1]) {
            freq_2[alphabet.find(c)]++;
        }

        for (int i = 0; i < 26; i++) {
            ans[i] += max(freq[i], freq_2[i]);
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << endl;
    }
}
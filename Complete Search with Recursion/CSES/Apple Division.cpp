// https://cses.fi/problemset/task/1623

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n;
vector<int> apples;

ll division(int i, ll sum1, ll sum2) {
    if (i == n) {
        return abs(sum1 - sum2);
    }
    return min(division(i + 1, sum1 + apples[i], sum2), division(i + 1, sum1, sum2 + apples[i]));
}

int main() {
    setIO();
    cin >> n;
    apples.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    cout << division(0, 0, 0) << endl;
}
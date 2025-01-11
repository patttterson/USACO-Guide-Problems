// https://usaco.org/index.php?page=viewproblem2&cpid=1203

#include <iostream>
#include <string>
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

int main() {
    setIO();

	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<int> elsie_log = vector<int>(n);
		int log_sum = 0;
		for (int &h : elsie_log) {
			cin >> h;
			log_sum += h;
		}

		for (int num_hours = 0; num_hours <= log_sum; num_hours++) {
			if (num_hours != 0 && log_sum % num_hours != 0) {
				continue;
			}

			int curr_sum = 0;
			bool valid = true;
			for (int h : elsie_log) {
				curr_sum += h;
				if (curr_sum > num_hours) {
					valid = false;
					break;
				} else if (curr_sum == num_hours) {
					curr_sum = 0;
				}
			}

			if (valid) {
				if (num_hours == 0) {
					cout << 0 << endl;
				} else {
					cout << n - log_sum / num_hours << endl;
				}
				break;
			}
		}
	}
}
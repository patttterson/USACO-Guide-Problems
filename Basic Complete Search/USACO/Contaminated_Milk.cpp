// https://usaco.org/index.php?page=viewproblem2&cpid=569

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Event {
	int person;
	int milk = -1;
	int time;
};

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("badmilk");

	int n, m, d, s;
	cin >> n >> m >> d >> s;

	vector<Event> events(d + s);
	for (int i = 0; i < events.size(); i++) {
		Event &ev = events[i];
		if (i < d) {
			cin >> ev.person >> ev.milk >> ev.time;
			ev.milk--;
		} else {
			cin >> ev.person >> ev.time;
		}
		ev.person--;
	}

	sort(events.begin(), events.end(), [&](const Event &e1, const Event &e2) {
		return e1.time != e2.time ? e1.time < e2.time : e1.milk < e2.milk;
	});

	int max_med = 0;
	for (int i = 0; i < m; i++) {
		vector<bool> can_be_sick(n);
		bool possible = true;
		for (const Event &e : events) {
			if (e.milk == -1) {
				if (!can_be_sick[e.person]) {
					possible = false;
					break;
				}
			} else if (e.milk == i) {
				can_be_sick[e.person] = true;
			}
		}

		if (possible) {
			int meds = 0;
			for (bool p : can_be_sick) { meds += p; }
			max_med = max(max_med, meds);
		}
	}

	cout << max_med << endl;
}
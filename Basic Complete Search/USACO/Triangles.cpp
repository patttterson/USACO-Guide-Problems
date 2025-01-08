// https://usaco.org/index.php?page=viewproblem2&cpid=1011

#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Point {
    int x, y;
};

bool check(Point a, Point b, Point c) {
    bool valid = false;

    if (a.x == b.x) {
        if (!valid) {
            valid = b.y == c.y || a.y == c.y;
        }
    }

    if (a.x == c.x) {
        if (!valid) {
            valid = b.y == c.y || a.y == b.y;
        }
    }

    if (b.x == c.x) {
        if (!valid) {
            valid = a.y == c.y || a.y == b.y;
        }
    }

    if (a.y == b.y) {
        if (!valid) {
            valid = b.x == c.x || a.x == c.x;
        }
    }

    if (a.y == c.y) {
        if (!valid) {
            valid = b.x == c.x || a.x == b.x;
        }
    }

    if (b.y == c.y) {
        if (!valid) {
            valid = a.x == c.x || a.x == b.x;
        }
    }

    return valid;
}

int main() {
    setIO("triangles");

    int n;
    cin >> n;

    Point posts[n];
    for (int i = 0; i < n; i++) {
        cin >> posts[i].x >> posts[i].y;
    }
    
    int max_area = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (check(posts[i], posts[j], posts[k])) {
                    double area = abs((posts[i].x*(posts[j].y - posts[k].y) + posts[j].x*(posts[k].y - posts[i].y) + posts[k].x*(posts[i].y - posts[j].y))/2.0);
                    max_area = max(max_area, (int)(area*2));
                }
            }
        }
    }

    cout << max_area << endl;
}
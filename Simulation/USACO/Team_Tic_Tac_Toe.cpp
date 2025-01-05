// https://usaco.org/index.php?page=viewproblem2&cpid=831

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

char board[3][3];
string char_set;

int single = 0, duo = 0;

set<set<char>> winners[3];

void valid(char c1, char c2, char c3) {
    set<char> chars;
    chars.insert(c1);
    chars.insert(c2);
    chars.insert(c3);

    winners[chars.size() - 1].insert(chars);
}

int main() {
    setIO("tttt");

    set<char> chars;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
            if (!chars.count(c)) {
                chars.insert(c);
                char_set += c;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        valid(board[i][0], board[i][1], board[i][2]);
        valid(board[0][i], board[1][i], board[2][i]);
    }

    valid(board[0][0], board[1][1], board[2][2]);
    valid(board[0][2], board[1][1], board[2][0]);

    cout << winners[0].size() << endl;
    cout << winners[1].size() << endl;
}
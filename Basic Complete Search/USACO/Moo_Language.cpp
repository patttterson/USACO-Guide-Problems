// https://usaco.org/index.php?page=viewproblem2&cpid=1324
// Unintended solution and/or not finished
#include <iostream>
#include <string>
#include <vector>
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

int main() {
    setIO();

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, c, p;
        cin >> n >> c >> p;

        vector<string> nouns, transitive, intransitive, conjunctions;
        for (int i = 0; i < n; i++) {
            string w, t;
            cin >> w >> t;
            if (t == "noun") {
                nouns.push_back(w);
            } else if (t == "transitive-verb") {
                transitive.push_back(w);
            } else if (t == "intransitive-verb") {
                intransitive.push_back(w);
            } else {
                conjunctions.push_back(w);
            }
        }

        // p = max sentences
        // noun + intransitive + "."
        // noun + transitive + (noun + ",")*c (remove last ,) + "."
        // sentence + conjunction + sentence + "."
        vector<string> sentences;
        while (true) {
            if (!nouns.size()) {
                break;
            }

            string sentence = nouns.back();
            nouns.pop_back();
            if (intransitive.size()) {
                sentence += " " + intransitive.back();
                intransitive.pop_back();
                sentences.push_back(sentence);
                continue;
            }

            // give each transitive verb one noun, then give the rest to the last transitive verb
            while (transitive.size() && nouns.size() > 1) {
                sentence += " " + transitive.back();
                transitive.pop_back();
                sentences.push_back(sentence + " " + nouns.back());
                nouns.pop_back();
            }
        }
    }
}
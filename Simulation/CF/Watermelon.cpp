// https://codeforces.com/problemset/problem/4/A

#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf((n % 4 == 0 || (n % 2 == 0 && n > 2)) ? "YES" : "NO");
}
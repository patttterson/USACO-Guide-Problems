// https://codeforces.com/problemset/problem/546/A

#include <cstdio>
using namespace std;

int calc(int n) { 
    return (n==1 || n==0) ? 1: n + calc(n - 1);  
} 

int main() {
    int k, n, w;
    scanf("%d%d%d", &k, &n, &w);
    int cost = calc(w) * k;
    int ans = cost - n;
    printf("%d", (ans < 0) ? 0 : ans);
}
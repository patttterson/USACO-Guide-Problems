// https://usaco.org/index.php?page=viewproblem2&cpid=1059
// Unintended solution and/or not finished

#include <cstdio>
#include <algorithm>
using namespace std;

int numbers[7];

int main() {
    scanf("%d%d%d%d%d%d%d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5], &numbers[6]);
    sort(numbers, numbers + 7);

    // numbers[0] is a
    // one element - numbers[0] is b
    // numbers[6] is a+b+c
    // numbers[6] - numbers[0] is b+c
    find(numbers, numbers + 7, numbers[6] - numbers[0]);
}
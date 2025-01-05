// https://cses.fi/problemset/task/1083

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 0; i < n-1; i++) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (nums[i] != i+1) {
            printf("%d\n", i+1);
            break;
        }
    }
}
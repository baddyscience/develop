#include <bits/stdc++.h>

using namespace std;

int nums[1000];

int main() {
    int n = 0;
    cin >> n;

    nums[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums+n+1);
    int first = 0, second = n;
    int m = 0;
    long long ans = 0;
    int h = 1;
    for (int i = 0; i < n; i++) {
        ans += (nums[first] - nums[second]) * (nums[first] - nums[second]);
        m = second;
        second = first + h;
        h = -h;
        first = m;
    }
    cout << ans << '\n';

    return 0;
}
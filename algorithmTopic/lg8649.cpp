#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long long n, k, t;
    cin >> n >> k;
    vector<long long> mods(n+5);
    vector<long long> sums(n+5);
    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        sums[i] += sums[i-1] + t;
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += mods[sums[i]%k]++;
    }
    cout << ans;
    return 0;
}
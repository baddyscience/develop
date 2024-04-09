#include <bits/stdc++.h>

using namespace std;

int main() {
    int dp[10] = {0};
    string s;
    int n, a, b, mx = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a = s[0] - '0', b = s.back() - '0';
        dp[b] = max(dp[b], dp[a]+1);
        mx = max(dp[b], mx);
    }

    cout << n - mx << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int dp[100005] = {0};
int flag = 0;
int gcb(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcb(y, x%y);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcb(g, a[i]);
        if (g == 1) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "INF";
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j < 100005; j++) {
            dp[j] = max(dp[j], dp[j-a[i]]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 100005; i++) {
        if (dp[i] == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
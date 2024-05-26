#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n = 0, m = 0;
    cin >> n >> m;
    long long goods[100005] = {0};
    long long s[100005] = {0}, t[100005] = {0}, p[100005] = {0}, c[100005] = {0}, g = 0, b = 0;
    int maxt = 0;
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> t[i] >> p[i] >> c[i];
        maxt = maxt > t[i] ? maxt : t[i];
        for (int j = 1; j <= c[i]; j++) {
            cin >> g >> b;
            goods[g] = b;
        }
    }

    long long ci = 0;
    long long price[100005] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxt; j++) {
            if (j >= s[i] && j <= t[i]) {
                price[j] += goods[i] * p[i] / 100;
            } else
                price[j] += goods[i];
        }
    }

    long long ans = LONG_LONG_MAX;
    for (int i = 1; i <= maxt; i++) {
        ans = ans < price[i] ? ans : price[i];
    }
    cout << ans << '\n';
    return 0;
}
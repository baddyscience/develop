#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio;

    long long a,b,p;
    cin >> a >> b >> p;
    long long x = b, n = a;
    long long ans = 1;
    while (x != 0) {
        if (x % 2 == 1) {
            ans = (ans * n) % p;
        }
        n = (n * n) % p;
        x /= 2;
    }
    cout << a << '^' << b << " mod ";
    cout << p << '=' << ans%p << '\n';

    return 0;
}
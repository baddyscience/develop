#include <iostream>
using namespace std;

long long p[10000010]={0}, n, mod=1e9+7;

int main() {
    long long n;
    cin >> n;
    p[0] = 1, p[1] = 1, p[2] = 2, p[3] = 5;
    for (int i = 3; i <= n; i++) {
        p[i] = p[i-1] * 2 + p[i-3];
        p[i] %= mod;
    }
    cout << p[n];
    return 0;
}
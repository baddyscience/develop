#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e8;
int n;
int primes[MAXN];
bool isPrime[MAXN];

int prime(int q) {
    int tot = 0;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) 
            primes[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * primes[j] > n)
                break;
            isPrime[i*primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
    return tot;
}

int main() {
    std::ios::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    prime(n);
    int s;
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << primes[s] << '\n';
    }

    return 0;
}


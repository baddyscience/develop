#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (4 * i * i > n)
            break;
        for (int j = 0; j < n; j++) {
            if (i * i + 4 * j * j > n)
                break;
            for (int k = 0; k < n; k++) {
                if (i * i + j * j+ 2 * k * k > n)
                    break;
                else {
                    int s = sqrt(n - i*i - j*j - k*k);
                    if (i*i+j*j+k*k+s*s == n) {
                        cout << i << " " << j << " " << k << " " << s;
                        goto a;
                    }
                }
            }
        }
    }
	a:
    return 0;
}
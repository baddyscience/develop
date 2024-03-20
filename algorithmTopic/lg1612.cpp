#include <iostream>

using namespace std;

const int maxn = 100000 + 5;
int sum[maxn];

int main() {
    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << endl;
    }


    return 0;
}
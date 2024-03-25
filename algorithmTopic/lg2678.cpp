#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, n, m, l, r;
int sum[50005];

bool half(int mid) {
    int ns = 0;
    int now = 0;
    for (int i = 1; i <= n+1; i++) {
        if (sum[i] - sum[now] < mid) {
            ns++;
        } else {
            now = i;
        }
    }
    if (ns <= m)
        return true;
    return false;
}

int main() {
    cin >> L >> n >> m;

    int ars = 0;
    sum[0] = 0;
    sum[n+1] = L;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
    }
    l = 1;
    r = L;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (half(mid)) {
            ars = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ars << endl;
    return 0;
}
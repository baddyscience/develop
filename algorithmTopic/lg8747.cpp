//寄，只有70分，回头再来研究
#include<bits/stdc++.h>
using namespace std;

long long s, n, m;
int ans[100005];

void jiang(long long k) {
    int nums[100005] = {0};
    for (int i = 1; i <= k ; i++) {
        nums[ans[i]] ++;
    }
    for (int i = 1; i <= n; i++) {
        if (nums[i]) {
            ans[k] = i;
            k--;
        }
    }
}

void sheng(long long k) {
    int nums[100005] = {0};
    for (int i = k; i <= n; i++) {
        nums[ans[i]]++;
    }
    for (int i = 0; i <= n; i++) {
        if (nums[i] == 1) {
            ans[k] = i;
            k++;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        ans[i] = i ;
    }
    long long c, k;
    for (int i = 0; i < m; i++) {
        cin >> c >> k;
        if (c == 0) {
            jiang(k);
        } else {
            sheng(k);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
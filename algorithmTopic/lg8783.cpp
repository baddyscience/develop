#include <iostream>
using namespace std;

long long n, m, k;
long long nums[505][505] = {0};
long long ans = 0;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
        cin >> nums[i][j];
        if (nums[i][j] <= k) {
            ans++;
        }
        nums[i][j] += nums[i][j-1];
        nums[i][j] += nums[i-1][j];
        nums[i][j] -= nums[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            long long t = 0;
            for (int x = 1;  x <= m; x++) {
                while( t+1 <= m && nums[t+1]-nums[x-1] <= k)
                    t++;
				if( t >= x ) {
					ans += t-x+1;
				}
            }
        }
    }
    cout << ans;
    return 0;
}
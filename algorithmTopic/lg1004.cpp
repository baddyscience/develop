#include <iostream>

using namespace std;

int nums[11][11];
int ans[11][11][11][11];
int n;

int main() {
    ios::sync_with_stdio;
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c && a) {
        nums[a][b] = c;
    }
    int i, j, l, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (l = 1; l <= n; l++) {
                for (k = 1; k <= n; k++) { //四维向量，四重循环，幽默，但也只能这么写了，递归也没差
                    ans[i][j][l][k] = max(max(ans[i-1][j][l-1][k], ans[i][j-1][l][k-1]), max(ans[i-1][j][l][k-1], ans[i][j-1][l-1][k])) + nums[i][j];
                    if (i != l && j != k) {
                        ans[i][j][l][k] += nums[l][k];
                    }
                }
            }
        }
    }

    cout << ans[n][n][n][n] << '\n';
    return 0;
}
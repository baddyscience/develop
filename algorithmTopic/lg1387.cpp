#include <iostream>

using namespace std;

const int maxn = 100 + 5;
int sum[maxn][maxn];
int fun[maxn][maxn];

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> sum[i][j];
            if (sum[i][j] == 1) 
                fun[i][j] = min(min(fun[i][j-1], fun[i-1][j]), fun[i-1][j-1]) + 1;
            ans = max(ans, fun[i][j]); 
        }
    }

    cout << ans <<endl;

    return 0;
}
#include<iostream>
using namespace std;

long long mod=1e9+7;
int n, m;
int dp[105][105][105];

int main() {
    cin >> n >> m;
    dp[0][0][2] = 1;

    for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j){
			if(!i && !j)
                continue;
			for(int k = 0; k<=m; ++k){
				if(k%2==0 && i) 
                    dp[i][j][k] += dp[i-1][j][k/2];
				if(j && k+1<=m)	
                    dp[i][j][k] += dp[i][j-1][k+1];
				dp[i][j][k] %= mod;
			}
		}

    cout << dp[n][m-1][1];
    return 0;
}
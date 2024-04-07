#include <bits/stdc++.h>

using namespace std;

int n = 0, t = 0;
char mp[1005][1005];
int sum = 0, ans = 0, cnt;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

void dfs(int x, int y) {
    if (!t) {
        cnt = 0;
        for (int i = 0; i < 4; i++) {
            if (mp[x+dx[i]][y+dy[i]] != '.') {
                cnt++;
            }
        }
        if (cnt == 4) {
            ans++;
            t = 1;
        }
    }
    mp[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n || mp[xx][yy] != '#')
            continue;
        dfs(xx, yy);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    } 
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (mp[i][j] == '#') {
                sum++;
                t = 0;
                dfs(i, j);
            }
        }
    }
    cout << sum - ans;
    return 0;
}
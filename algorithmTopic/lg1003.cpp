#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10000 + 5;

int a[MAXN], b[MAXN], g[MAXN], k[MAXN];

int main() {
    int n, x, y;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i]; 
    }
    cin >> x >> y;
    
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]) {
            ans = i + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
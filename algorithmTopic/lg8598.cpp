#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    long long n, x, a[100005] = {0};
    cin >> n;
    while(cin >> x) {
        a[x]++;
    }
    int t = 0, d = 0, c = 0;
	for (int i = 0; i < 100003; i++) {
		if (a[i] > 0 && a[i+1] == 0 && a[i+2] > 0) {
			d = i+1;
			t++;
		}
		if (a[i] == 2) {
			c = i;
			t++;
		}
		if (t == 2) {
			break;
		}
	}
	cout << d << " " << c;
    return 0;
}
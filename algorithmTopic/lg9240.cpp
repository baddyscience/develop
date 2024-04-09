#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long a, b, c, d;
    long long maxx = 999999999, minx = -1;
    while (n--) {
        cin >> a >> b;
        c = a / (b + 1) + 1;
        d = a / b;
        minx = max(c, minx);
        maxx = min(d, maxx);
    }
    cout << minx << " " << maxx;
    return 0;
}
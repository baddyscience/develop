#include <iostream>
using namespace std;
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = 5*a + 2*b;
    long long ans = c / sum * 7;
    c = c % sum;
    long long s = 0;
    long long n[7] = {a, a, a, a, a, b, b};
    for (int i = 0; i < 7; i++) {
        if (s < c) {
        ans ++;
        s += n[i];
        } else {
        break;
        }
    }
    cout << ans;
    return 0;
}
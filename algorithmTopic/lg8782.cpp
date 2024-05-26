#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long num1[100005] = {0}, num2[100005] = {0};
    int m1, m2;
    cin >> m1;
    for (int i = m1; i > 0; i--) {
        cin >> num1[i];
    }
    cin >> m2;
    for (int i = m2; i > 0; i--) {
        cin >> num2[i];
    }
    int m = max(m1, m2);
    long long arr = 0;
    long long t = 1, x = 1;
    for (int i = 1; i <= m; i++) {
        arr += (num1[i] - num2[i]) * t;
        x = max(num1[i], num2[i]) + 1;
        while (x == 1) {
            x++;
        }
        t *= x;
        t %= 1000000007;
        arr %= 1000000007;
    }
    cout << arr;
    return 0;
}
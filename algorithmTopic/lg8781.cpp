#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int nums[10005] = {0};
    int y = (n+1) / 2;
    int i = 1;
    while (i <= y) {
        nums[i] = (n-i) * 2;
        cout << nums[i] << endl;
        i++;
    }
    if (n % 2 == 0) {
        i--;
        while (i > 0) {
        cout << nums[i] << endl;
        i--;
        }
    } else {
        i--;
        i--;
        while (i > 0) {
        cout << nums[i] << endl;
        i--;
        }
    }
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int n;
int s[3000001], arr[3000001];
stack<int> nums;

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = n; i > 0; i--) {
        while (!nums.empty() && s[nums.top()] <= s[i])
        {
            nums.pop();
        }
        arr[i] = nums.empty() ? 0 : nums.top();
        nums.push(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
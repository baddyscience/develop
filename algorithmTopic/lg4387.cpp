#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio;

    int n;
    stack<int> nums;
    int m, s[100005], k[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool t = true;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> s[j];
        }
        for (int j = 0; j < m; j++) {
            cin >> k[j];
        }
        int head = 0;
        for (int j = 0; j < m; j++) {
            nums.push(s[j]);
			while(nums.top() == k[head])
			{
				nums.pop();
				head++;
				if(nums.empty())
				break;
			}
        }
        if (nums.empty())
        	cout << "Yes" << endl;
        else
        	cout << "No" << endl;
        while (!nums.empty()) {
        	nums.pop();
		}
    }

    return 0;
}
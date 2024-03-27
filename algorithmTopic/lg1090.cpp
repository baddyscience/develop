#include <bits/stdc++.h>

using namespace std;

priority_queue<long long,vector<long long>,greater<long long> > q;//优先队列…小优先 
long long ans;
int n,t,x,y;

int main() {
    ios::sync_with_stdio;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        q.push(t);
    }

    for (int i = 0; i < n - 1; i++) {//求合只需n-1次循环
        x = q.top();
		q.pop();
     	y = q.top();
		q.pop();
     	ans += x+y;
		q.push(x+y);
    }
    cout<<ans;

    return 0;
}
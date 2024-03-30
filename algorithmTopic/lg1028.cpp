#include <bits/stdc++.h>

using namespace std;

// 递归法
//看着很美，狠狠的超时,题目标签有递归，递归却过不了，幽默
// int count(int n) {
// 	if ( n == 1 ) return 1;
// 	else if(n == 2) return 2;
// 	else if(n%2 == 1) return count( n-1 );
// 	else return count(n/2) + count( n-1);  
// }

// int main() {
//     int n;
//     cin >> n;

//     cout << count(n) << '\n';
//     return 0;
// }

int f[1001] = {0, 1};
void count(int n) {
    int i,j;
    for ( i = 2; i <= n; i++)
    {
        for ( j=1; j<=i/2; j++)
         f[i] = f[i] + f[j];
         f[i] = f[i] + 1; 
    }
}

int main() {
    int n;
    cin >> n;
    count(n);
    cout << f[n];
    return 0;
}
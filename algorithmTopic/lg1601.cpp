#include <bits/stdc++.h>

using namespace std;

int a[505], b[505], c[505];

int init(int a[]) {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        a[i] = s[len - 1 - i] - '0';
    }
    return len;
}

int main() {
    int lena = init(a);
    int lenb = init(b);
    int lenc = max(lena, lenb);
    for(int i = 0; i < lenc; i++)
	{
		c[i] += a[i]+b[i];
		if(c[i]>=10)
		{
			c[i+1]++;
			c[i]%=10;
		}
	}
	while(c[lenc]==0 && lenc>0)
		lenc--;
	for(int i=lenc;i>=0;i--)
		cout<<c[i];

    return 0;
}
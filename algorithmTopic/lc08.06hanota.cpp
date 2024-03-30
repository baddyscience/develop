#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
{
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();  // 删除最后一个元素
            return;
        }
        move(n - 1, A, C, B); // 移动n-1个盘子从A移动到B
        C.push_back(A.back()); // 移动第n个盘子从A到C
        A.pop_back(); 
      
        move(n- 1, B, A, C); // 移动n-1个盘子从B移动到C
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }
int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	hanota(a,b,c);
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<' ';	
	}

	return 0; 
}

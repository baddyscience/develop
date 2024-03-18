#include <iostream>

using namespace std;

const int MAXN = 1000 + 5; // + 1会溢出，这个错误排除了好久，吐血三升
int arr[MAXN][MAXN];

int main() {
    int n,m;
    cin >> n >> m;

    //1.暴力解法
    // for (int i = 0; i < m; i++) {
    //     int x1,y1,x2,y2;
    //     cin >> x1 >> y1 >> x2 >> y2;

    //     for (int i = x1; i <= x2; i++) {
    //         for (int j = y1; j <= y2; j++)
    //             arr[i][j]++;
    //     }
    // }
    //打印结果
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j  <= n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    //2.差分法
    for (int i = 0; i < m; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j <= x2; j++) {
            arr[j][y1]++;
            arr[j][y2 + 1]--;
        }
    }
    //还原并打印结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += arr[i][j-1];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
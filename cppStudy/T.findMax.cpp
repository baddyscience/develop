// 设计一个函数模板，实现从int、long long、char、double、string类型的数组找出最大值元素。
// 提示：可用类型参数传递数组、用非类型参数传递数组大小。
// 请完成以下程序：

#include <iostream>
#include <string>
using namespace std;

//你的代码放在这里
template<typename T>
T findMax(T* array, int size) {
    T maxElement = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for ( int i = 0; i < n; i++ )
         cin >> a[i] ;
    cout << "1 " << findMax( a, n ) << endl;
    delete[] a;

    cin >> n;
    string *b = new string[n];
    for ( int i = 0; i<n; i++ )
         cin >> b[i] ;
    cout << "2 " << findMax( b, n ) << endl;
    delete[] b;

    cin >> n;
    long long *c = new long long[n];
    for ( int i = 0; i<n; i++ )
         cin >> c[i] ;
    cout << "3 " << findMax( c, n ) << endl;
    delete[] c;

    cin >> n;
    double *d = new double[n];
    for ( int i = 0; i<n; i++ )
         cin >> d[i] ;
    cout << "4 " << findMax( d, n ) << endl;
    delete[] d;

    return 0;
}

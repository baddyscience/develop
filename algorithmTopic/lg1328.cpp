#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200 + 1;

int A[MAXN], B[MAXN];

int vs[5][5] = {{0, 0, 1, 1, 0},{1, 0, 0, 1, 0},{0, 1, 0, 0, 1},{0, 0, 1, 0, 1},{1, 1, 0, 0, 0}};

int main() {
    int n, a, b, suma, sumb;
    cin >> n >> a >> b;

    suma = 0, sumb = 0;
    for (int i = 0; i < a; i++)
        cin >> A[i];

    for (int i = 0; i < b; i++)
        cin >> B[i];

    for (int i = 0; i < n; i++) {
        suma += vs[A[i % a]][B[i % b]];
        sumb += vs[B[i % b]][A[i % a]];
    }

    cout << suma << " " << sumb << endl;
    return 0;
}
#include <iostream>

int main() {
    int mounth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    
    for (int y = 1960; y <= 2059; y++) {
        if ((y % 4 == 0 && y % 100 != 0 ) || ( y % 400 == 0)) {
            mounth[1] = 29;
        } else {
            mounth[1] = 28;
        }
        for (int m = 1; m <= 12; m++) {
            for (int d = 1; d <= mounth[m-1]; d++) {
                if ((a == y%100 && b == m && c == d) || 
                    (c == y%100 && a == m && b == d) ||
                    (c == y%100 && b == m && a == d)) {
                        printf("%d-%02d-%02d\n", y, m, d);
                }
            }
        }
    }
    return 0;
}
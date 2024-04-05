#include <bits/stdc++.h>

using namespace std;

bool isString(string xs) {
    bool t = false;
    if (xs[0] == xs[7] && xs[1] == xs[6] && xs[2] == xs[5] && xs[3] == xs[4])
        t = true;
    return t;
}

bool isAb(string xs) {
    char a = xs[0], b =xs[1];
    bool t = false;
    if (xs[2] == a && xs[3] == b && xs[4] == b && xs[5] == a && xs[6] == b && xs[7] == a)
        t = true;

    return t;
}

int main() {
    string s;
    cin >> s;
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
    int mounth = (s[4]-'0')*10+(s[5]-'0');
    int day = (s[6]-'0')*10+(s[7]-'0');
    int t = 0;
    for (int i = year+1; i < 9999; i++) {
        if ((i % 4 ==0 && i % 100 != 0) || (i % 400 ==0)) mdays[1] = 29;
        else mdays[1] = 28;
        for (int j = 1; j <= 12; j++) {
            for (int k = 1; k <= mdays[j-1]; k++) {
                int x = i*10000 + j*100 + k;
                string xs = to_string(x);
                if (t == 0) {
                    if (isString(xs)) {
                        cout << x << endl;
                        t++;
                    }
                }
                if (t < 2) {
                    if (isAb(xs)) {
                        cout << x << endl;
                        goto a;
                    }
                }
            }
        }
    }
    a:
    return 0;
}
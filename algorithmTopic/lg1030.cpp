#include<iostream>
#include<cstring>

using namespace std;

void before(string a, string b) {
    if(a.size() == 0)
        return;
    char ch = b[b.size() - 1];
    cout << ch;
    int k = a.find(ch);
    before(a.substr(0, k), b.substr(0, k));
    before(a.substr(k+1), b.substr(k, a.size()-k-1));
}

int main() {
    ios::sync_with_stdio;

    string a, b;
    cin >> a >> b;
    before(a, b);
    cout << '\n';
    return 0;
}
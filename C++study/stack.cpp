#include <iostream>

using namespace std;

class Stack {
private:
    int* data;
    int tt;
    int len;

public:
    Stack(): tt(-1),len(1000) {
        data = new int[len];
        cout << "constructing" << endl;
    }

    ~Stack() {
        delete[] data;
        cout << "destructing" << endl;
    }

    bool top(int &v) {
        if (tt >= 0) {
            v = data[tt];
            return true;
        }
        return false;
    }

    void pop() {
        if (tt >= 0) {
            tt--;
        }
    }

    void push(int v) {
        if (tt + 1 < len) {
            tt++;
            data[tt] = v;
        }
    }

    int size() {
        return tt + 1;
    }

    void output() {
        for (int i = 0; i <= tt; i++) {
            cout << data[i] << " "; 
        }
        if (tt >= 0) {
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Stack stack;

    for (int i = 0; i < n; i++) {
        int commend;
        cin >> commend;
        if (commend == 1) {
            int a;
            cin >> a;
            stack.push(a);
        } else if (commend == 2) {
            stack.pop();
        } else if (commend == 3) {
            int v;
            cin >> v;
            if (stack.top(v)) {
                cout << v << endl;
            }
        } else if (commend == 4) {
            cout << stack.size() << endl;
        } else if (commend == 5) {
            stack.output();
        }
    }

    return 0;
}

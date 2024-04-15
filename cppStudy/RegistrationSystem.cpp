// 注册系统-map
// 一个名为 “Berlanddesk” 的电子邮件系统即将在 Berland 上线运营。
// 该电子邮件系统的管理员希望整个系统的建设可以尽早完成，因此他们找到了资深程序员您，希望您能够为他们开发一个用户注册系统的原型产品。

// 该系统的运行遵循以下原则:
// 新用户注册时，他将向系统发送一则内容为其用户名的请求，如果该用户名尚未存在于系统数据库内，则将该用户名插入数据库，同时用户得到回应信息 OK 表示其已经成功注册。
// 如果用户请求的用户名已经存在于数据库内，那么系统将产生一个新的用户名并将其加入数据库。
// 新用户名由用户请求的用户名与正整数 i 构成，i 为使 “用户名i” 尚未存在于数据库内的最小的 i 。

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> registry;
    string username;

    for (int i = 0; i < n; ++i) {
        cin >> username;
        if (registry.find(username) == registry.end()) {
            registry[username] = 1;
            cout << "OK" << endl;
        } else {
            int counter = registry[username];
            string new_username;
            while (true) {
                new_username = username + to_string(counter);
                if (registry.find(new_username) == registry.end()) {
                    registry[new_username] = 1;
                    registry[username]++;
                    cout << new_username << endl;
                    break;
                }
                counter++;
            }
        }
    }

    return 0;
}

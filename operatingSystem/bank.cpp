#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Process
{
public:
    string Name;            // 进程名
    vector<int> Max;        // 最大需求量
    vector<int> Allocation; // 已分配资源数
    vector<int> Need;       // 仍需资源数
    bool Unassigned;        // true【未标记】
};

void showMenu();                      // 实现菜单功能
void addProcess(vector<Process> &);   // 添加进程
void showProcess(vector<Process> &);  // 展示进程表
void clearProcess(vector<Process> &); // 清空进程
void Banker(vector<Process> &);       // 多资源银行家算法
bool isSafe(vector<Process> &, vector<int> &, vector<int> &); // 安全性检查

// 全局变量
int num; // 进程数量
int cpt; // 资源种类数量
int ccpt[10005]; // 系统资源

int main(void)
{
    vector<Process> v; // 进程表

    while (true)
    {
        showMenu();

        int select = 0;
        cout << endl
             << "请输入您选择的操作：";
        cin >> select;
        switch (select)
        {
        case 0:
            cout << "您已退出银行家算法，欢迎下次使用!";
            return 0;
            break;
        case 1:
            addProcess(v);
            break;
        case 2:
            showProcess(v);
            break;
        case 3:
            Banker(v);
            break;
        case 4:
            clearProcess(v);
            break;
        default:
            cout << "请输入正确的命令！";
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}

void showMenu()
{
    cout << "\t*********************************\t" << endl;
    cout << "\t********* 银行家算法模拟 ********\t" << endl;
    cout << "\t********** 1、添加进程 **********\t" << endl;
    cout << "\t********** 2、展示进程 **********\t" << endl;
    cout << "\t********* 3、银行家算法 *********\t" << endl;
    cout << "\t********** 4、清空进程 **********\t" << endl;
    cout << "\t******** 0、退出算法模拟 ********\t" << endl;
    cout << "\t*********************************\t" << endl;
}

void addProcess(vector<Process> &v)
{
    cout << "请输入添加进程的数量：";
    cin >> num;
    cout << "请输入系统资源种类数：";
    cin >> cpt;
    cout << "请输入系统资源容量：";
    for (int i = 0; i < cpt; i++)
    {
        cin >> ccpt[i];
    }

    int elem; // 输入容器的数据

    for (int i = 0; i < num; i++)
    {
        Process mp;
        cout << "添加第" << i << "进程" << endl;
        cout << "请输入进程名：";
        cin >> mp.Name;
        cout << "请输入最大需求量：";
        for (int j = 0; j < cpt; j++)
        {
            cin >> elem;
            mp.Max.push_back(elem);
        }
        cout << "请输入已分配资源数：";
        for (int j = 0; j < cpt; j++)
        {
            cin >> elem;
            mp.Allocation.push_back(elem);
        }
        mp.Need.resize(cpt);
        for (int j = 0; j < cpt; j++)
        {
            mp.Need[j] = mp.Max[j] - mp.Allocation[j];
        }

        mp.Unassigned = true; // 默认未标记
        v.push_back(mp);
        cout << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

void showProcess(vector<Process> &v)
{
    if (v.size() == 0)
    {
        cout << "进程表无数据" << endl;
    }
    else
    {
        cout << "进程表如下：" << endl
             << endl;
        cout << "Process\tMax\tAllocation\tNeed" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i).Name << "\t";
            for (int Max = 0; Max < v.at(i).Max.size(); Max++)
            {
                cout << v.at(i).Max.at(Max) << " ";
            }
            cout << "\t";
            for (int Allocation = 0; Allocation < v.at(i).Max.size(); Allocation++)
            {
                cout << v.at(i).Allocation.at(Allocation) << " ";
            }
            cout << "\t\t";
            for (int Need = 0; Need < v.at(i).Need.size(); Need++)
            {
                cout << v.at(i).Need.at(Need) << " ";
            }
            cout << endl;
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}

void clearProcess(vector<Process> &v)
{
    v.clear();
    if (v.size() == 0)
    {
        cout << "进程表已被清空" << endl;
    }
    system("pause");
    system("cls");
}

bool isSafe(vector<Process> &v, vector<int> &work, vector<int> &safeSequence) {
    vector<bool> finish(v.size(), false);
    safeSequence.clear();
    bool canProceed;

    do {
        canProceed = false;
        for (int i = 0; i < v.size(); i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < cpt; j++) {
                    if (v[i].Need[j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < cpt; j++) {
                        work[j] += v[i].Allocation[j];
                    }
                    finish[i] = true;
                    safeSequence.push_back(i);
                    canProceed = true;
                }
            }
        }
    } while (canProceed);

    for (bool f : finish) {
        if (!f) return false;
    }
    return true;
}

void Banker(vector<Process> &v)
{
    vector<int> request(cpt);
    int processIndex;
    cout << "请输入请求资源的进程编号：";
    cin >> processIndex;

    cout << "请输入请求资源数量：";
    for (int i = 0; i < cpt; i++) {
        cin >> request[i];
    }

    // 步骤（1）
    for (int j = 0; j < cpt; j++) {
        if (request[j] > v[processIndex].Need[j]) {
            cout << "错误：请求的资源数量超过进程的最大需求量。" << endl;
            return;
        }
    }

    // 步骤（2）
    for (int j = 0; j < cpt; j++) {
        if (request[j] > ccpt[j]) {
            cout << "当前资源不足，进程需要等待。" << endl;
            return;
        }
    }

    // 步骤（3）
    for (int j = 0; j < cpt; j++) {
        ccpt[j] -= request[j];
        v[processIndex].Allocation[j] += request[j];
        v[processIndex].Need[j] -= request[j];
    }

    // 步骤（4）
    vector<int> work(ccpt, ccpt + cpt);
    vector<int> safeSequence;
    if (isSafe(v, work, safeSequence)) {
        cout << "资源已成功分配。" << endl;
        cout << "找到安全序列：";
        for (int i = 0; i < safeSequence.size(); i++) {
            cout << safeSequence[i] << " ";
        }
        cout << endl;
    } else {
        // 恢复原状态
        for (int j = 0; j < cpt; j++) {
            ccpt[j] += request[j];
            v[processIndex].Allocation[j] -= request[j];
            v[processIndex].Need[j] += request[j];
        }
        cout << "分配资源后系统处于不安全状态，分配失败。" << endl;
    }

    system("pause");
    system("cls");
}

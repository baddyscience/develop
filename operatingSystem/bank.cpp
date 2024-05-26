#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Process
{
public:
    string Name;            // ������
    vector<int> Max;        // ���������
    vector<int> Allocation; // �ѷ�����Դ��
    vector<int> Need;       // ������Դ��
    bool Unassigned;        // true��δ��ǡ�
};

void showMenu();                      // ʵ�ֲ˵�����
void addProcess(vector<Process> &);   // ��ӽ���
void showProcess(vector<Process> &);  // չʾ���̱�
void clearProcess(vector<Process> &); // ��ս���
void Banker(vector<Process> &);       // ����Դ���м��㷨
bool isSafe(vector<Process> &, vector<int> &, vector<int> &); // ��ȫ�Լ��

// ȫ�ֱ���
int num; // ��������
int cpt; // ��Դ��������
int ccpt[10005]; // ϵͳ��Դ

int main(void)
{
    vector<Process> v; // ���̱�

    while (true)
    {
        showMenu();

        int select = 0;
        cout << endl
             << "��������ѡ��Ĳ�����";
        cin >> select;
        switch (select)
        {
        case 0:
            cout << "�����˳����м��㷨����ӭ�´�ʹ��!";
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
            cout << "��������ȷ�����";
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
    cout << "\t********* ���м��㷨ģ�� ********\t" << endl;
    cout << "\t********** 1����ӽ��� **********\t" << endl;
    cout << "\t********** 2��չʾ���� **********\t" << endl;
    cout << "\t********* 3�����м��㷨 *********\t" << endl;
    cout << "\t********** 4����ս��� **********\t" << endl;
    cout << "\t******** 0���˳��㷨ģ�� ********\t" << endl;
    cout << "\t*********************************\t" << endl;
}

void addProcess(vector<Process> &v)
{
    cout << "��������ӽ��̵�������";
    cin >> num;
    cout << "������ϵͳ��Դ��������";
    cin >> cpt;
    cout << "������ϵͳ��Դ������";
    for (int i = 0; i < cpt; i++)
    {
        cin >> ccpt[i];
    }

    int elem; // ��������������

    for (int i = 0; i < num; i++)
    {
        Process mp;
        cout << "��ӵ�" << i << "����" << endl;
        cout << "�������������";
        cin >> mp.Name;
        cout << "�����������������";
        for (int j = 0; j < cpt; j++)
        {
            cin >> elem;
            mp.Max.push_back(elem);
        }
        cout << "�������ѷ�����Դ����";
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

        mp.Unassigned = true; // Ĭ��δ���
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
        cout << "���̱�������" << endl;
    }
    else
    {
        cout << "���̱����£�" << endl
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
        cout << "���̱��ѱ����" << endl;
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
    cout << "������������Դ�Ľ��̱�ţ�";
    cin >> processIndex;

    cout << "������������Դ������";
    for (int i = 0; i < cpt; i++) {
        cin >> request[i];
    }

    // ���裨1��
    for (int j = 0; j < cpt; j++) {
        if (request[j] > v[processIndex].Need[j]) {
            cout << "�����������Դ�����������̵������������" << endl;
            return;
        }
    }

    // ���裨2��
    for (int j = 0; j < cpt; j++) {
        if (request[j] > ccpt[j]) {
            cout << "��ǰ��Դ���㣬������Ҫ�ȴ���" << endl;
            return;
        }
    }

    // ���裨3��
    for (int j = 0; j < cpt; j++) {
        ccpt[j] -= request[j];
        v[processIndex].Allocation[j] += request[j];
        v[processIndex].Need[j] -= request[j];
    }

    // ���裨4��
    vector<int> work(ccpt, ccpt + cpt);
    vector<int> safeSequence;
    if (isSafe(v, work, safeSequence)) {
        cout << "��Դ�ѳɹ����䡣" << endl;
        cout << "�ҵ���ȫ���У�";
        for (int i = 0; i < safeSequence.size(); i++) {
            cout << safeSequence[i] << " ";
        }
        cout << endl;
    } else {
        // �ָ�ԭ״̬
        for (int j = 0; j < cpt; j++) {
            ccpt[j] += request[j];
            v[processIndex].Allocation[j] -= request[j];
            v[processIndex].Need[j] += request[j];
        }
        cout << "������Դ��ϵͳ���ڲ���ȫ״̬������ʧ�ܡ�" << endl;
    }

    system("pause");
    system("cls");
}

#include <iostream>

using namespace std;

struct Node {
   int data;
   Node *next;

   Node() {
       data = 0;
       next = nullptr;
   }

   ~Node() { }
};

class List {
private:
    Node *head;

public:
    List() : head(nullptr) { }

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int pos, int value) {
        Node** temp = &head;
        while (*temp != nullptr && pos > 0) {
            temp = &((*temp)->next);
            --pos;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = *temp;
        *temp = newNode;
    }

    void deleteByPos(int pos) {
        if (head == nullptr) return;
        Node** temp = &head;
        while (*temp != nullptr && pos > 1) {
            temp = &((*temp)->next);
            --pos;
        }
        if (*temp != nullptr) {
            Node* toDelete = *temp;
            *temp = (*temp)->next;
            delete toDelete;
        }
    }

    void deleteByValue(int value) {
        Node** temp = &head;
        while (*temp != nullptr && (*temp)->data != value) {
            temp = &((*temp)->next);
        }
        if (*temp != nullptr) {
            Node* toDelete = *temp;
            *temp = (*temp)->next;
            delete toDelete;
        } else {
            cout << "not found data: " << value << endl;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
   List l1;  /// 创建一个空链表对象 l1

   l1.insert(0, 10); /// 在第 0 个节点的后面插入值为 10 的新节点，也即在链表头部插入新的节点
   l1.insert(0, 66);
   l1.insert(1, 292);  /// 在第 1 个节点的后面插入值为 292 的新节点
   l1.print();  /// 从头到尾输出链表节点的值，每个值后跟一空格

   l1.deleteByValue(66);  /// 删除链表中第一个值为 66 的节点
   l1.print();

   l1.insert(2, -2);  /// 在第 2 个节点的后面插入值为 -2 的新节点
   l1.insert(1, 3);  /// 在第 1 个节点的后面插入值为 3 的新节点
   l1.print();

   l1.deleteByPos(2);  /// 删除链表中第2个位置的节点，那么“3”就被删掉了
   l1.print();

   l1.deleteByValue(999); // 尝试删除一个不存在的值
   l1.print();

   return 0;
}
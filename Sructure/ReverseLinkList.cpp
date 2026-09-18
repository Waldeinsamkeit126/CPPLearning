
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int x) : data(x), link(nullptr) {}
};

class List {
public:
    Node* reverse(Node* head) {
        Node* pre = nullptr;
        Node* cur = head;
        while(cur != nullptr){
            Node* next = cur->link;
            cur->link = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void printList(Node* head) {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->link;
        }
        cout << endl;
    }
};

int main() {
    // 构建链表 1->2->3->4->5
    Node* head = new Node(1);
    head->link = new Node(2);
    head->link->link = new Node(3);
    head->link->link->link = new Node(4);
    head->link->link->link->link = new Node(5);

    List list;
    cout << "原链表: ";
    list.printList(head);

    head = list.reverse(head);
    cout << "反转后: ";
    list.printList(head);

    return 0;
}
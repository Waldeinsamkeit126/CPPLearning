#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct LinkedList {
    Node* head;
};
void insert(Node*&, int);
void delete_front(Node*&);
void print(Node* const);
int main() {
    Node* head = nullptr;
    for (int i = 0; i < 100; ++i)
        insert(head, i);
    for (int i = 0; i < 50; ++i)
        delete_front(head);
    print(head);
    while (head)
        delete_front(head);
    return 0;
}
void insert(Node*& head, int x) {
    /*
    Node *u = new Node;
    (*u).data = x; // u -> data = x;
    (*u).next = head;
    head = u;
    */
    head = new Node({ x, head });
}
void delete_front(Node*& head) {
    Node* u = head->next;
    delete head;
    head = u;
}
void print(Node* const head) {
    /*
    Node *iter = head;
    while (iter != nullptr) {
        cout << iter -> data << ' ';
        iter = iter -> next;
    }*/
    for (Node* iter = head; iter; iter = iter->next)
        cout << iter->data << ' ';
    cout << '\n';
}
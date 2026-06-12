#include <iostream>
using namespace std;
struct Node {
    double data;
    Node* next;
};
struct LinkedList {
    Node* head;
    void insert_front(double);
    void insert_after(Node*, double);
    void delete_front();
    void delete_after(Node*);
    Node* find(double);
    void print();
};
int main() {
    LinkedList list({ nullptr });
    for (int i = 0; i < 10; ++i)
        list.insert_front(.1 * i);
    list.insert_after(list.find(.5), 3.14);
    list.delete_after(list.find(3.14));
    list.delete_front();
    list.print();
    while (list.head)
        list.delete_front();
    return 0;
}
void LinkedList::insert_front(double x) {
    head = new Node({ x, head });
}
void LinkedList::insert_after(Node* u, double x) {
    /*
    Node *v = new Node({x, u -> next});
    u -> next = v;
    */
    u->next = new Node({ x, u->next });
}
void LinkedList::delete_front() {
    Node* u = head;
    head = head->next;
    delete u;
}
void LinkedList::delete_after(Node* u) {
    Node* v = u->next;
    u->next = u->next->next;
    delete v;
}
Node* LinkedList::find(double x) {
    for (Node* iter = head; iter; iter = iter->next)
        if (iter->data == x)
            return iter;
    return nullptr;
}
void LinkedList::print() {
    for (Node* iter = head; iter; iter = iter->next)
}
cout << iter->data << ' ';

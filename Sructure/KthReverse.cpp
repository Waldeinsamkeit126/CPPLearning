#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr){}
};

Node* reverseK(Node* head, int k){
    if (head == nullptr  || k <= 1){
        return head;
    }
    Node dummy(0);
    dummy.next = head;

    Node* PreGroup = &dummy;

    while(true){
        Node* kth = PreGroup;
        for(int i = 0; i < k; i++){
            kth = kth -> next;
            if (kth == nullptr){
                return dummy.next;
            }
        }

        Node* NextGroup = kth -> next;

        Node* prev = NextGroup;
        Node* cur = PreGroup -> next;

        while(cur != NextGroup){
            Node* nextone = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nextone;
        }

        Node* oldFirst = PreGroup -> next;
        PreGroup -> next =kth;
        PreGroup = oldFirst;
    }
}
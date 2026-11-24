#include <iostream>
using namespace std;
// 前置声明
template <class Type> class CircList;
template <typename Type> void Josephus(CircList<Type> &Js, int n, int m);
template <class Type> class CircLinkNode {
    friend class CircList<Type>;
    friend void Josephus<Type>(CircList<Type> &Js, int n, int m);
public:
    CircLinkNode(Type d = 0, CircLinkNode<Type> *next = NULL)
        : data(d), link(next) { }  //构造函数
private:
    Type data;  //结点数据
    CircLinkNode<Type> *link;  //链接指针
};
template <class Type> class CircList {
friend void Josephus<Type> (CircList <Type> &Js, int n, int m);
    private:
         CircLinkNode <Type> *first, *last, *current;
     //循环链表的表头指针、尾指针和当前元素指针
    public:
         CircList(): first(nullptr), last(nullptr), current(nullptr){};
         CircList(CircList <Type> &L);
CircLinkNode <Type> * GetHead( ) const{return first;}
    void Insert(Type &x){
    //Q1: 在循环链表的末尾插入结点
    CircLinkNode <Type>* newNode = new CircLinkNode<Type> (x);
    if(first == nullptr){
        first = newNode;
        last = newNode;
        last -> link = first;
    }
    else{
        newNode -> link = first;
        last -> link =newNode;
        last = newNode;
    }
}
};
template <typename Type>
void Josephus (CircList <Type> &Js, int n, int m)
{
    CircLinkNode <Type> *p=Js.GetHead( ), *pre=NULL;
    for (int i=0; i<n-1; i++) {  //执行n-1次
     //Q2: 每次删除一位参与者
        for (int j = 1; j < m; j++){
            pre = p;
            p = p -> link;
        }
        if (p == Js.first){
            Js.first = p -> link;
        }
        if (p == Js.last){
            Js.last = pre;
        }
        pre -> link =p -> link;
        CircLinkNode<Type>* q = p;
        p = p -> link;

        delete q;
    }
    cout << "Last one: " << p->data << endl;
}
int main( ) {
    CircList <int> clist;
    int n, m;
    cout<<"Input the number of participants and the magic number: " ;
    cin>>n>>m;  //形成约瑟夫环
    for (int i=1; i<=n; i++) clist.Insert(i);
    Josephus<int>(clist, n, m);  //解决约瑟夫问题
return 0;
}
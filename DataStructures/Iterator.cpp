#include <iostream>
using namespace std;
template <class Type> class List;  //List类的前向引用声明
template <class Type> class ListIterator;
template <class Type> class ListNode {  //链表结点类定义
      friend class List <Type>;  //链表类作为友元类定义
      friend class ListIterator <Type>;

      public:
      ListNode(const Type &item) : data(item), link(NULL) {};  //带形参的构造函数
      private:
 Type data;  //数据域
 ListNode <Type> *link;  //后继指针域
};
template <class Type> class List {  //单链表类定义
      friend class ListIterator <Type>;
      public:
        List() : first(NULL){};
void append(Type item) {
          ListNode<Type> * newNode = new ListNode<Type>(item);
          //Q1: 把生成的新结点插入到列表最后
          if(first==NULL){
            first = newNode;
          }
          else{
            ListNode<Type> *p = first;
            while(p->link != NULL){
                p = p->link;
            }
            p -> link =newNode;
          }
}

      private:
ListNode <Type> *first;
            //链表的表头指针
};
template <class Type> class ListIterator {
private:
  const List<Type> & list;
  ListNode<Type> *current;
public:
     ListIterator(const List <Type> &l)
  : list(l), current(l.first) { }
     //构造函数: 引用链表l，表头为当前结点
     ListNode <Type> *First( ){
       return list.first;
     };  //返回第一个结点
     ListIterator<Type> & operator++ (){
       if (current != NULL)
         current = current->link;
       return *this;
     };
     Type currentData(){
       return current -> data;
     }
     //返回链表当前结点的下一个结点的地址
     Type sum(){
         Type total = 0;
         //Q2: 求列表上所有结点中所存储的数据总和
        current=First();
        while(current != NULL){
            total += currentData();
            ++(*this);
        }
         return total;
     }
};
int main(){
  List<int> list;
  for (int i = 1; i<=10; i++)
    list.append(i);
  ListIterator<int> li(list);
  cout << li.sum();
  return 0;
}
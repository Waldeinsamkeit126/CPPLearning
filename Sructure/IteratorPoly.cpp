#include <iostream>
using namespace std;
template <typename T>
class Polynomial {
private:
    struct Node {
        T coef;
        int exp;
        Node* link;
        Node(T c, int e, Node* l = NULL)
            : coef(c), exp(e), link(l) {}
    };
    Node* first;
public:
    class Iterator {
    public:
        Node* current;
        Iterator(Node* n) : current(n) {}
        Iterator& operator++() {
            if (current) current = current->link;
            return *this;
        }
        Node * operator*(){
            return current;
        }
    };
    Polynomial() : first(NULL) {}
    ~Polynomial() { freeList(first); }
    void freeList(Node* p){
      while (p){
  Node* q = p->link;
  delete p;
  p = q;
      }
    }
    Polynomial& operator=(const Polynomial& poly){
      if (this != &poly){
        freeList(first);
first = NULL;
Node* p = poly.first;
while (p) {append(p->coef, p->exp); p = p->link; }
      }
      return *this;
    }
  
    void append(T c, int e){
   if (first == NULL){
    first = new Node(c,e);
    return;
   }
        Node *p = first;
        while (p->link != NULL)
        p = p -> link;
         p -> link = new Node(c,e);
        };
    void display(){
          if (first == NULL)
      cout << "0";
  Node * p = first;
  bool firstTerm = true;
  while (p != NULL){
            if (!firstTerm && p -> coef > 0)
      cout << "+";
    if (p->coef != 1.0)
      cout << p -> coef;
        if (p->exp != 0)
      cout << "x";
    if (p->exp > 1)
      cout << "^" << p->exp;
    firstTerm = false;
    p = p -> link;
  }
      cout << endl;
};
    Polynomial<T> operator+(const Polynomial<T>& B) const {
        Polynomial<T> C;
        Iterator it1(first);
        Iterator it2(B.first);
        while ((*it1) != NULL && (*it2) != NULL) {
  // Q1：补充代码实现多项式的加法
            if((*it1) -> exp < (*it2) -> exp){
                C.append((*it1) -> coef, (*it1) -> exp);
                ++it1;
            }
            else if((*it1) -> exp > (*it2) -> exp){
                C.append((*it2) -> coef, (*it2) -> exp);
                ++it2;
            }
            else{
                if((*it1) -> coef +(*it2) -> coef !=0){
                    C.append((*it1) -> coef + (*it2) -> coef, (*it1) -> exp);
                }
                    ++it1;
                    ++it2;
            }
        }
        while ((*it1) != NULL) {
            C.append((*it1)->coef, (*it1) -> exp);
            ++it1;
        }
        while ((*it2) != NULL) {
            C.append((*it2) -> coef, (*it2) -> exp);
            ++it2;
        }
        return C;
    }
  Polynomial<T> operator*(const Polynomial<T>& B) const{
    Polynomial<T> result;
    Iterator itB(B.first);
    // Q2：补充代码实现多项式的乘法
    while ((*itB) != NULL){
        Polynomial<T> temp;
      Iterator itA(first);
      while((*itA) != NULL){
        T newCoef = (*itA) -> coef * (*itB) -> coef;
        int newExp = (*itA) -> exp +(*itB) -> exp;
        temp.append(newCoef, newExp);
        ++itA;
      }
      result = result + temp;
      ++itB;
    }
    return result;
  }
};
int main() {
    Polynomial<float> A, B;
  A.append(1.8, 0);
  A.append(6.0, 10);
  A.append(3.8, 12);
  B.append(1.2, 0);
  B.append(-6.0, 10);
  B.append(5.12, 15);
  Polynomial<float> C = A + B;
   cout << "A(x) = ";
   A.display();
   cout << "B(x) = ";
   B.display();
   cout << "C(x) = A(x) + B(x) = ";
   C.display();
   Polynomial<float> D = A * B;
   cout << "D(x) = A(x) * B(x) = ";
   D.display();
   return 0;
}
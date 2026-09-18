#include <iostream>
#define MAXN 20
using namespace std;
class Polynomial;  //多项式类的前向引用声明
class term {  //多项式中项的类定义
    friend class Polynomial;  //定义多项式类为term类的友元类
    private:
        float coef;  //系数
        int exp;  //指数
};
class Polynomial {  //多项式类定义
    public:
        //无形参构造函数，返回多项式A(x)=0
        Polynomial() : free(0){
     Poly_Array = new term[MAXN];
        };
        int operator ! ( );  //若*this是零多项式则返回1，否则返回0
        int Poly_Append(float c, int e);
        Polynomial Poly_Add(Polynomial poly);
        //返回多项式*this与多项式poly的和
        Polynomial Poly_Subtract(Polynomial poly);
        //返回多项式*this与多项式poly的差
        Polynomial Poly_Mult(Polynomial poly);
        //返回多项式*thiAs与多项式poly的乘积
        Polynomial Poly_Division(Polynomial poly);
        //返回多项式*this与多项式poly的商
        void display() {
            if (free == 0) {
                cout << "0" << endl;
                return;
            }

            for (int i = 0; i < free; i++) {
                // 处理系数为1或-1的情况
                if (Poly_Array[i].coef == 1.0f && Poly_Array[i].exp != 0) {
                    // 不显示系数1
                } else if (Poly_Array[i].coef == -1.0f && Poly_Array[i].exp != 0) {
                    cout << "-";  // 只显示负号
                } else {
                    cout << Poly_Array[i].coef;
                }

                // 处理指数
                if (Poly_Array[i].exp > 0) {
                    cout << "x";
                    if (Poly_Array[i].exp > 1) {
                        cout << "^" << Poly_Array[i].exp;
                    }
                }

                // 处理正负号显示
                if (i < free - 1 && Poly_Array[i + 1].coef >= 0) {
                    cout << "+";
                }
            }
            cout << endl;
        }

    private:
        term *Poly_Array;  //存放多项式的数组
        //要求在类外定义
        //Polynomial :: Poly_Array= new Term [MAXN+1];
        int free;  //多项式有效项数的下一位置
        //int start, finish;
};
char compare(int i, int j){
  char c;
  if (i == j)
    c = '=';
  else if (i < j)
    c = '<';
    else
      c = '>';
  return c;
};
int Polynomial :: Poly_Append(float c, int e)
{  //增加一项在起始空闲存储单元处
       if (free>MAXN)
 return 1;
           //无可用空闲存储单元，不能插入
       Poly_Array[free].coef=c;
       Poly_Array[free++].exp=e;
       return 0;
}
Polynomial Polynomial :: Poly_Add(Polynomial B)
{  //返回两个多项式A(x)（在*this中）与B(x)的和
   //假设多项式以升幂次序排列
      Polynomial C;
      int ah=0;
      int bh=0;
      //ah与bh分别为两个多项式的检测指针
      //Q: 补充代码实现多项式的加法
      while(ah < free&&bh < B.free){
        switch(compare(Poly_Array[ah].exp, B.Poly_Array[bh].exp)){
    case '=':
        if (Poly_Array[ah].coef + B.Poly_Array[bh].coef !=0 ){
            C.Poly_Append(Poly_Array[ah].coef + B.Poly_Array[bh].coef,Poly_Array[ah].exp);
        }
        ah++;
        bh++;
        break;
    case '<':
        C.Poly_Append(Poly_Array[ah].coef, Poly_Array[ah].exp );
        ah++;
        break;
    case '>':
        C.Poly_Append(B.Poly_Array[bh].coef, B.Poly_Array[bh].exp );
        bh++;
        break;
        }
      }
      while(ah < free){
        C.Poly_Append(Poly_Array[ah].coef, Poly_Array[ah].exp );
        ah++;
      }
    while(bh < free){
        C.Poly_Append(B.Poly_Array[bh].coef, B.Poly_Array[bh].exp );
        bh++;
      }
     return C;
}
int main(){
  Polynomial A, B, C;
  A.Poly_Append(1.8, 0);
  A.Poly_Append(6.0, 10);
  A.Poly_Append(3.8, 12);
  B.Poly_Append(1.2, 0);
  B.Poly_Append(-6.0, 10);
  B.Poly_Append(5.12, 15);
  C = A.Poly_Add(B);
    cout << "A(x) = ";
    A.display();

    cout << "B(x) = ";
    B.display();

    cout << "C(x) = A(x) + B(x) = ";
    C.display();

}
#include <iostream>
#include <queue>
using namespace std;
void yanghui(int n) {
//在输出上一行系数时，将其下一行的系数预先
//放入队列中，在各行系数之间插入一个0
    queue<int> q;  //队列初始化
    int i=1, j;
    int s=0, t;
    q.push(i);  q.push(i);
    //预先放入第一行的两个系数
    for (int i=1; i<=n; i++) {  //逐行计算
        cout<<endl;
        q.push(0);
       // Q: 计算并打印第i行的所有系数
       for(j = 1; j <= i + 1; j++){
        t = q.front();
        q.pop();
        cout << t << " ";
        q.push(s + t);
        s = t;
        }
        q.pop();
        q.push(1);
        s = 0;
        }
    }

int main(){
  yanghui(5);
  return 0;
}

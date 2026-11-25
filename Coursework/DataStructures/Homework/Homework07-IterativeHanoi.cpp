#include <iostream>
#include <stack>
using namespace std;

struct HanoiTask{
    int n;
    char source;
    char auxiliary;
    char target;

    HanoiTask(int n, char s, char a, char t):
        n(n), source(s), auxiliary(a), target(t){}
};

void hanoiStack(int n, char source, char auxiliary, char target){
    stack<HanoiTask> taskStack;
    taskStack.push(HanoiTask(n, source, auxiliary, target));
    while(!taskStack.empty()){
         HanoiTask task = taskStack.top();
         taskStack.pop();
         if(task.n == 1){
            cout << "MOVE DISK FROM "
                 << task.source << " TO "
                 << task.target << endl;
         }
         else{
            taskStack.push(HanoiTask(
                task.n - 1,
                task.auxiliary,
                task.source,
                task.target));
            taskStack.push(HanoiTask(
                1,
                task.source,
                task.auxiliary,
                task.target));
            taskStack.push(HanoiTask(
                task.n - 1,
                task.source,
                task.target,
                task.auxiliary));
         }
    }
}

int main() {
    int n;
    cin >> n;
    hanoiStack(n, 'A', 'B', 'C');
    return 0;
}

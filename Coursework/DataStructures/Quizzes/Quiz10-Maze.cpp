/*
#include <iostream>
using namespace std;

const int ROW = 6;
const int COL = 10;

int maze[ROW][COL]={
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
{1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool dfs(int x, int y){
    if (x < 0 || x >= ROW || y < 0 || y >= COL) return false;
    if (maze[x][y] != 0) return false;
    maze[x][y] = 2;
    if(x == 4 && y == 9) return true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny)) return true;
    }
    maze[x][y] = 0;
    return false;
}

int main(){
    if (dfs(1, 0)){
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if (maze[i][j] == 2) cout << "* ";
                else cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout << "NO PATH" << endl;
    return 0;
}
*/

#include <iostream>
#include <stack>
using namespace std;

const int ROW = 6;
const int COL = 10;

int maze[ROW][COL]={
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
{1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct Position{
    int x;
    int y;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool findPath(int startX, int startY, int endX, int endY){
    stack<Position> s;
    s.push({startX, startY});
    maze[startX][startY] = 2;
    while (!s.empty()){
        Position cur = s.top();
        if(cur.x == endX && cur.y == endY){
            return true;
        }
        bool found =false;
        for (int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= ROW || ny < 0 || ny >= COL){
                continue;
            }
            if (maze[nx][ny] == 0){
                maze[nx][ny] = 2;
                s.push({nx, ny});
                found = true;
                break;
            }
        }
        if(!found){
            maze[cur.x][cur.y] = 3;
            s.pop();
        }
    }
    return false;
}

int main(){
    if(findPath(1, 0, 4, 9)){
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if (maze[i][j] == 2) cout << "* ";
                else if(maze[i][j] == 3) cout <<"0 ";
                else cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO PATH" << endl;
    }
    return 0;
}

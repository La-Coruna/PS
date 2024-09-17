/* 
[알파벳]
- date: 24.09.17
- 분류: backtracking, dfs
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[20];
bool issued[26];

int max_move_cnt = 0;
int move_cnt = 1;

int R, C;

void move(int x, int y){
    //cout << "("  << x << ", " << y << ")" << "[" << board[x][y] << "]" << "["<<move_cnt<<"] -> ";
    bool canGo = false;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=R||ny>=C) continue;
        if(issued[board[nx][ny] - 'A']) continue;
        canGo = true;
        issued[board[nx][ny] - 'A'] = true;
        move_cnt++;
        move(nx, ny);
        move_cnt--;
        issued[board[nx][ny] - 'A'] = false;
        //cout << "";
    }
    if(!canGo){
        // 이동 끝.
        max_move_cnt = max(max_move_cnt,move_cnt);
        //cout << "end! \n";
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for(int i = 0; i < R; i++)
        cin >> board[i];

    issued[board[0][0] - 'A'] = true;
    move(0,0);

    cout << max_move_cnt;

    return 0;
}
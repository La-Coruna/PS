/*
[순서대로 방문하기] 
- date: 24.10.28
- url: https://softeer.ai/practice/6246
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, m;
int board[4][4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int answer = 0;
bool vis[4][4];
void func(int cur_x, int cur_y, int nextNum){
    //cout << cur_x << ", " << cur_y << " -> ";
    if(nextNum == m+1) {
        //cout << "\nanswer up!\n";
        answer++;
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];
        if(nx < 0||ny < 0||nx >= n||ny >= n) continue;
        if(vis[nx][ny]||board[nx][ny] == 1||board[nx][ny] > nextNum) continue;
        vis[nx][ny] = true;
        if(board[nx][ny] == nextNum) func(nx, ny, nextNum+1);
        else func(nx, ny, nextNum);
        vis[nx][ny] = false;
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    int st_x, st_y;
    cin >> st_x >> st_y;
    st_x--; st_y--;
    for(int i = 2; i < 1+m; i++){
        int u, v;
        cin >> u >> v;
        board[u-1][v-1] = i;
    }
    vis[st_x][st_y] = true;
    func(st_x, st_y,2);

    cout << answer;

    return 0;
}
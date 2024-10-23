/*
[HSAT 1회 정기 코딩 인증평가 기출] 로봇이 지나간 경로
- date: 24.10.08
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6275?id=280&resourceId=329
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// 상 우 하 좌
// L : 우(lastDir:1) -> 상(curDir:0) | curDir - lastDir == -1 | 상(lastDir:0) -> 좌(curDir:3) | curDir - lastDir == 3
// R : 상(lastDir:0) -> 우(curDir:1) | curDir - lastDir == 1 | 좌(lastDir:3) -> 상(curDir:0) | curDir - lastDir == -3
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char dirSign[4] = {'^','>','v','<'};

int H, W;
string board[25];
bool vis[25][25];
string cmd;

pair<int,int> FindStartPoint(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] != '#') continue;
            int adjCnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0|| ny < 0 || nx >= H || ny >= W) continue;
                if(board[nx][ny] == '#') adjCnt++;
            }
            if(adjCnt == 1) return {i,j};
        }
    }
    return {-1,-1};
}

int FindDir(int x, int y){
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0|| ny < 0 || nx >= H || ny >= W) continue;
        if(board[nx][ny] == '#' && !vis[nx][ny]) return k;
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> board[i];
    }

    pair<int,int> cur = FindStartPoint();
    cout << cur.X + 1<< ' ' << cur.Y + 1 << '\n';

    vis[cur.X][cur.Y] = true;

    int lastDir = FindDir(cur.X,cur.Y);
    cout << dirSign[lastDir] << '\n';
    while(true){
        int curDir = FindDir(cur.X,cur.Y);
        if(curDir == -1) break;
        int dirDiff = curDir - lastDir;
        // L
        if(dirDiff == -1 || dirDiff == 3)
            cmd += 'L';
        // R
        if(dirDiff == 1 || dirDiff == -3)
            cmd += 'R';
        // move
        cur.X += dx[curDir];
        cur.Y += dy[curDir];
        vis[cur.X][cur.Y] = true;
        cur.X += dx[curDir];
        cur.Y += dy[curDir];
        vis[cur.X][cur.Y] = true;
        cmd += 'A';

        lastDir = curDir; 
    }

    cout << cmd;

    return 0;
}
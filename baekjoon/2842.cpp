/*
[집배원 한상덕] 
- date: 25.02.04
- 분류: bfs, two pointers
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[9] = {-1,-1,-1,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,1,-1,0,1};

set<int> heightSet;

int N;
char board[50][50];
int height[50][50];
pair<int,int> P;
int houseNum = 0;

int bfs(int lb, int hb){
    if(height[P.X][P.Y] < lb || height[P.X][P.Y] > hb) return false;

    int remainingCnt = houseNum;

    bool vis[50][50];
    for(int i = 0; i < N; i++)
        fill(vis[i], vis[i]+N, false);
    queue<pair<int,int>> Q;

    vis[P.X][P.Y] = true;
    Q.push(P);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i < 9; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny]) continue;
            if(height[nx][ny] < lb || height[nx][ny] > hb) continue;

            vis[nx][ny] = true;
            Q.emplace(nx,ny);
            if(board[nx][ny] == 'K') remainingCnt--;
        }
    }
    
    return remainingCnt == 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 'P') P = {i,j};
            else if(board[i][j] == 'K') houseNum++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> height[i][j];
            heightSet.emplace(height[i][j]);
        }
    }

    int minDiff = 0x7fffffff;
    for(auto st = heightSet.begin(), en = heightSet.begin(); st != heightSet.end() ;){
        bool canGo = bfs(*st,*en);
        if(canGo){
            minDiff = min(minDiff,*en - *st);
            if(st == en && en != heightSet.end()) en++;
            else st++;
        } else{
            if(en != heightSet.end()) en++;
            else break;
        }
    }

    cout << minDiff;

    return 0;
}
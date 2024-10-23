/*
[아기 상어]
- date: 24.10.22
- 분류: BFS
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;
int board[20][20];

int sharkSize = 2, eatCnt = 0, t = 0;
pair<int,int> sharkPos;

void printBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(sharkPos.X == i && sharkPos.Y == j) cout << "9 ";
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool sharkMove(pair<int,int> curPos){
    queue<pair<int,int>> Q;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fish;
    int vis[20][20] = {0};
    int minDist = 0;

    vis[curPos.X][curPos.Y] = 1;
    Q.emplace(curPos);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny] != 0 || board[nx][ny] > sharkSize) continue;
            if(board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
                if(fish.empty()) {fish.emplace(nx,ny); minDist = vis[cur.X][cur.Y];}
                else if(minDist == vis[cur.X][cur.Y]) fish.emplace(nx,ny);
            }
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.emplace(nx,ny);
        }
    }
    if(!fish.empty()){
        auto curfish = fish.top(); fish.pop();
        board[curfish.X][curfish.Y] = 0;
        t += minDist;
        sharkPos = curfish;
        if(++eatCnt == sharkSize){
            sharkSize++;
            eatCnt = 0;
        }
        return 1;
    }
    else return 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9) {
                board[i][j] = 0;
                sharkPos = {i,j};
            }
        }
    }

    while(sharkMove(sharkPos)){;}
    cout << t;

    return 0;
}
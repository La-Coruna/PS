/*
[내리막 길] 
- date: 25.10.01
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M;
int board[500][500];
int dp[500][500];
priority_queue<tuple<int,int,int>> pq;


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    pq.emplace(board[0][0], 0, 0);
    dp[0][0] = 1;

    while(!pq.empty()){
        auto [curH, curX, curY] = pq.top(); pq.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] >= curH) continue;
            if(dp[nx][ny] == 0)  // 각 칸당 한번만 pq에 들어가도록 조건 설정
                pq.emplace(board[nx][ny], nx, ny);
            dp[nx][ny] += dp[curX][curY];
        }
    }

    cout << dp[N-1][M-1] << '\n';

    return 0;
}
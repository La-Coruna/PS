/*
[치즈] 
- date: 26.04.19
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M, board[100][100], cheese_cnt, last_cheese_cnt, t;
bool vis[100][100];
queue<pair<int,int>> Q;
vector<pair<int,int>> melting_reservation;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) cheese_cnt++;
        }
    }

    vis[0][0] = true;
    Q.emplace(0,0);

    for(t = 0; cheese_cnt > 0; t++){
        last_cheese_cnt = cheese_cnt;
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                // 지금 방문한 곳이, 처음 방문한 치즈 칸이면
                if(board[nx][ny] == 1) {
                    // 다음 시간에 녹도록 체크
                    melting_reservation.emplace_back(nx,ny);
                    continue;
                }
                Q.emplace(nx,ny);
            }
        }
        for(auto& [x,y] : melting_reservation){
            board[x][y] = 0;
            cheese_cnt--;
            Q.emplace(x,y);
        }
        melting_reservation.clear();
    }
    
    cout << t << '\n' << last_cheese_cnt;


    return 0;
}
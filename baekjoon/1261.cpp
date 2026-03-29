/*
[알고스팟] 
- date: 26.03.29

- 비용 갱신이 꼭 있어야 되나?? 진짜 모르겠음. 없이 해도 이 문제는 솔브는 되긴 하던데.
- 갱신이 없으면 안되는 반례를 떠올리기가 힘들다.
- 갱신1: if(vis[nx][ny] <= vis[x][y] + 1) continue
- 갱신2: if(vis[nx][ny] <= vis[x][y]) continue;
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char board[100][100];
int N, M;

int bfs_0_1(){
    deque<pair<int,int>> Q;
    int vis[100][100];
    for(int i = 0; i < N; i++){
        fill(vis[i],vis[i]+M,999);
    }

    Q.emplace_front(0,0);
    vis[0][0] = 0;

    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop_front();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽 부수고 이동
            if(board[nx][ny] == '1'){
                if(vis[nx][ny] <= vis[x][y] + 1) continue;
                vis[nx][ny] = vis[x][y] + 1;
                Q.emplace_back(nx,ny);
            }
            // 일반 이동
            else{
                if(vis[nx][ny] <= vis[x][y]) continue;
                vis[nx][ny] = vis[x][y];
                Q.emplace_front(nx,ny);
            }
        }
    }
    return vis[N-1][M-1];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    cout << bfs_0_1();

    return 0;
}
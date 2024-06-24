/* 
[토마토]
- date: 24.06.24
- 분류: BFS - 최단 거리 구하기

- 시작 점이 여러개인 BFS 문제
*/
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[1001][1001];
int vis[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int maxDist = 0;

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                Q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    // 처음부터 모든 토마토가 익어 있음 -> 0
    bool isAlreadyRipen = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 0){
                isAlreadyRipen = false;
                break;
            }
        }
    }
    if(isAlreadyRipen){
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] > 0 || board[nx][ny] == -1) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            board[nx][ny] = 1;
            maxDist = max(maxDist,vis[nx][ny]);
            Q.push({nx,ny});
        }
    }

    // 토마토가 모두 익지 못 함 -> -1
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << maxDist -1;   

    return 0;
}
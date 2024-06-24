/* 
[미로 탐색]
- date: 24.06.23
- 분류: BFS - 최단 거리 구하기

- 띄어쓰기가 안되어 있으면 아싸리 string으로 받아버리자.
- 다음 좌표의 거리를 구할 때, 이전 좌표의 거리에 +1을 하면 된다.
*/
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    string board[102];
    int vis[102][102] = {0};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> Q;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        //cout<< "(" << cur.X << ", " << cur.Y << ")[" << vis[cur.X][cur.Y] << "] -> ";
        for(int d = 0; d < 4; d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] > 0|| board[nx][ny] != '1') continue;
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }

    cout << vis[N-1][M-1];

    return 0;
}
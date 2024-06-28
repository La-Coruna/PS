/* 
[토마토]
- date: 24.06.25
- 분류: BFS
 */
#include <bits/stdc++.h>

using namespace std;

int board[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int vis[101][101][101];
queue<tuple<int,int,int>> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int maxDay = 0;
    int unripe = 0;
    int M, N, H;
    cin >> M >> N >> H;

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cin >> board[x][y][z];
                if(board[x][y][z] == 1){
                    vis[x][y][z] = 1; //초기값을 1일로 설정했기 때문에, 정답은 1을 빼줘야함.
                    Q.push(make_tuple(x,y,z));
                } else if(board[x][y][z] == 0){
                    unripe++;
                }
            }
        }
    }
    if(unripe == 0){
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 6; i++){
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
            if(vis[nx][ny][nz] > 0 || board[nx][ny][nz] == -1) continue;
            vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push(make_tuple(nx,ny,nz));
            maxDay = max(vis[nx][ny][nz],maxDay);
            unripe--;
        }
    }

    if(unripe != 0)
        cout << -1;
    else
        cout << maxDay-1;
    return 0;
}
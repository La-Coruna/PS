/* 
[벽 부수고 이동하기]
- date: 24.06.30
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;
#define X(t) get<0>(t)
#define Y(t) get<1>(t)
#define WallBreaking(t) get<2>(t) // false면 아직 안 부순 경우

int vis[1003][1003][2];
string board[1003];
queue<tuple<int,int,bool>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];

    vis[0][0][false] = 1;
    Q.push(make_tuple(0,0,false)); // 문제에선 (1,1).
    while(!Q.empty()){
        tuple<int,int,bool> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = X(cur) + dx[i];
            int ny = Y(cur) + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 다음 칸이 벽이일 때
            if(board[nx][ny] == '1'){
                //부술 수 없다면
                if(WallBreaking(cur)) continue;
                //부술 수 있다면
                else {
                    // BFS 특성상 짧은 거리를 먼저 탐색. 대소 비교 안 해도 됨.
                    if(vis[nx][ny][true] > 0) continue;
                    vis[nx][ny][true] = vis[X(cur)][Y(cur)][false] + 1;
                    Q.push(make_tuple(nx,ny,true));
                    continue;
                }
            } 
            // 다음 칸이 길일 때
            if(vis[nx][ny][WallBreaking(cur)] > 0) continue; // 부순 경우와 안 부순 경우를 비교해야할까? 안 해도 될 듯.
            vis[nx][ny][WallBreaking(cur)] = vis[X(cur)][Y(cur)][WallBreaking(cur)] + 1;
            Q.push(make_tuple(nx,ny,WallBreaking(cur)));
        }
    }

    int noBreaking = (vis[N-1][M-1][0] == 0) ? 10000000 : vis[N-1][M-1][0];
    int Breaking = (vis[N-1][M-1][1] == 0) ? 10000000 : vis[N-1][M-1][1];
    int answer = min(noBreaking,Breaking);
    cout << ((answer == 10000000) ? -1 : answer);

    return 0;
}
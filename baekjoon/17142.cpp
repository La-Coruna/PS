/*
[연구소 3] 
- date: 

- 바이러스 놓고 bfs 돌리고, 바이러스 또 다르게 놓고 bfs 돌리고 반복

- 고려하지 못했던 엣지 케이스
4 1
1 1 1 1
1 2 1 1
1 1 1 1
1 1 2 0
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int N, M;
int board[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,int>> vPos;
vector<bool> isSelected;
int minTime = INF;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) {
                vPos.emplace_back(i,j);
                isSelected.emplace_back(0);
            }
        }
    }

    fill(isSelected.rbegin(), isSelected.rbegin()+M, 1);
    
    do{
        vector<vector<int>> vis(N, vector<int>(N,-1));
        queue<pair<int,int>> Q;

        for(int i = 0; i < vPos.size(); i++){
            if(!isSelected[i]) continue;
            auto [x,y] = vPos[i];
            vis[x][y] = 0;
            Q.emplace(x,y);
        }

        while(!Q.empty()){
            auto [curX, curY] = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++){
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(vis[nx][ny] != -1 || board[nx][ny] == 1) continue;
                // 방문 했었는데, 더 일찍 방문했던 경우
                vis[nx][ny] = vis[curX][curY] + 1;
                Q.emplace(nx,ny);
            }
        }

        // 다 전파됐는지 확인
        bool isFailed = false;
        int totalTime = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 방문 안 한 곳
                if(vis[i][j] == -1) {
                    // 틀렸던 생각: 방문 안 했는데 벽이 아니야? 바로 조기 종료.
                    // 틀렸던 이유: 벽 말고도 비활성 바이러스일 수도 있음. 이 경우는 조기 종료 하면 안됨.
                    // 옳은 생각: 방문 안했는데, 방문해야 하는 곳이야? 바로 조기 종료
                    if(board[i][j] == 0){
                        isFailed = true;
                        break;
                    }
                    continue;
                }
                // 이미 바이러스 칸인 경우는 시간 계산 X
                if(board[i][j] == 2) continue;
                totalTime = max(totalTime,vis[i][j]);
            }
            if(isFailed) break;
        }
        if(isFailed) continue;

        minTime = min(minTime,totalTime);
    }
    while(next_permutation(isSelected.begin(),isSelected.end()));

    if(minTime == INF) cout << -1;
    else cout << minTime;

    return 0;
}
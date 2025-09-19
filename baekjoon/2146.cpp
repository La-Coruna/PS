/*
[다리 만들기] 
- date: 2025.09.19
- 분류: BFS
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, board[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int areaId[101][101];
bool isBorder[101][101];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    // 1. 섬의 가장자리를 찾고, ID 부여
    int curAreaId = 0;
    bool vis[101][101] = { false };
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 섬이 아니거나, 방문한 곳이면 패스
            if(board[i][j] == 0 || vis[i][j]) continue;

            curAreaId++;

            // BFS로 그 섬을 전부 돌며 가장자리 체크 및 ID 부여
            areaId[i][j] = curAreaId;
            vis[i][j] = true;
            Q.emplace(i,j);
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    // 1. 사방을 조사 하는 중인데 바다 발견. 그렇다면 현재 땅은 가장자리
                    if(board[nx][ny] == 0){
                        isBorder[cur.X][cur.Y] = true;
                        continue;
                    }
                    // 2. 옆 땅이 땅인 경우 로직 계속 진행.
                    if(vis[nx][ny]) continue;
                    areaId[nx][ny] = curAreaId;
                    vis[nx][ny] = true;
                    Q.emplace(nx,ny);
                }
            }
            
        }
    }

    // 2. 각 가장자리 땅에서 출발해, 다른 대륙의 가장자리까지의 최단거리 구해서, 그들의 최소값 구하기
    int answer = 0x7fffffff;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 가장자리가 아니면 pass
            if(!isBorder[i][j]) continue;

            int min_dist = 0x7fffffff;

            int dist[101][101] = {0};
            dist[i][j] = 1;
            Q.emplace(i,j);
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(dist[nx][ny]) continue;

                    // case 1) 탐방 중 육지 발견
                    if(board[nx][ny] == 1){
                        // 다른 섬의 가장자리가 아니면 PASS = (가장자리 아니면 PASS) (나랑 같은 섬이면 PASS)
                        if(!isBorder[nx][ny] || areaId[i][j] == areaId[nx][ny]) continue;

                        // 나랑 다른 섬이면! 다른 섬과의 최소 거리 발견
                        min_dist = dist[cur.X][cur.Y];

                        // BFS 조기 종료
                        while(!Q.empty()) Q.pop();
                        break;
                    }

                    // case 2) 탐방 중 바다 발견 -> 계속 항해해~
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q.emplace(nx,ny);
                }
            }
            answer = min(min_dist, answer);
        }
    }

    cout << answer - 1;

    return 0;
}
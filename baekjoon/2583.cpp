/* 
[영역 구하기]
- date: 24.06.28
- 분류: BFS

- x, ny 변수명을 까먹고 x,y로 적는 실수 주의.
 */
#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool board[102][102];
bool vis[102][102];
int area[10002];
int cnt = 0;
queue<pair<int,int>> Q;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N, K; // M:세로 N:가로
    cin >> M >> N >> K;
    while(K--){
        int xs, ys, xe, ye; // 문제에서 가로가 x축
        cin >> xs >> ys >> xe >> ye;
        for(int y = ys; y < ye; y++){
            for(int x = xs; x < xe; x++){
                board[y][x] = true;
            }
        }
    }

    for(int y = 0; y < M; y++){
        for(int x = 0; x < N; x++){
            if(vis[y][x]||board[y][x]) continue;
            vis[y][x]=true;
            Q.push({y,x});
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                area[cnt]++;
                for(int i = 0; i < 4; i++){
                    int ny = cur.Y + dy[i];
                    int nx = cur.X + dx[i];
                    if(ny<0||nx<0||ny>=M||nx>=N) continue;
                    if(vis[ny][nx] || board[ny][nx]) continue;
                    vis[ny][nx] = true;

                    Q.push({ny,nx});
                }
            }
            cnt++;
        }
    }

    sort(area, area+cnt);
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++) cout << area[i] << " ";
    return 0;
}
/* 
[나이트의 이동]
- date: 24.06.28
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        queue<pair<int,int>> Q;
        int vis[301][301] = {0}; // 0으로 초기화 해서 답은 1 빼야함.
        int boardSize, sx, sy, ex, ey;
        cin >> boardSize >> sx >> sy >> ex >> ey;

        vis[sx][sy] = 1;
        Q.push({sx,sy});
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            if(cur.X == ex && cur.Y == ey){
                cout << vis[cur.X][cur.Y] - 1<< '\n';
                break;
            }
            for(int i = 0; i < 8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize) continue;
                if(vis[nx][ny]>0) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    return 0;
}
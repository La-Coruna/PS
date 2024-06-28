/* 
[불]
- date: 24.06.28
- 분류: BFS

        (x-1,y)
(x,y-1) (x,y)   (x,y+1)
        (x+1,y)
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int answer; // 300*300 = 90000
        string board[1001] = {};
        int vis[1001][1001] = {};
        int visFire[1001][1001] = {};
        queue<pair<int,int>> Q;
        queue<pair<int,int>> QFire;
        bool isEscaped = false;
        int w, h;
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            cin >> board[i];
            for(int j = 0; j < w; j++){
                if(board[i][j] == '@'){
                    vis[i][j] = 1;
                    Q.push({i,j});
                } else if(board[i][j]=='*'){
                    visFire[i][j] = 1;
                    QFire.push({i,j});
                }
            }
        }
        // 불 이동
        while(!QFire.empty()){
            pair<int,int> cur = QFire.front(); QFire.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx<0||ny<0||nx>=h||ny>=w) continue;
                if(visFire[nx][ny] > 0 || board[nx][ny] == '#') continue;
                visFire[nx][ny] = visFire[cur.X][cur.Y] + 1;
                QFire.push({nx,ny});
            }
        }
        // 상근이 이동
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx<0||ny<0||nx>=h||ny>=w){
                    //크기를 벗어나면 탈출한 것임
                    answer = vis[cur.X][cur.Y];
                    isEscaped = true;
                    break;
                };
                if(vis[nx][ny] > 0 || board[nx][ny] != '.') continue;
                int nowDist = vis[cur.X][cur.Y] + 1;
                if(visFire[nx][ny]>0 && nowDist >= visFire[nx][ny]) continue;
                vis[nx][ny] = nowDist;
                Q.push({nx,ny});
            }
            if(isEscaped) break;
        }

        if(isEscaped) cout << answer << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
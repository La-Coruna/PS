/* 
[섬의 개수]
- date: 24.09.09
- 분류: BFS
 */

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h;
    while(true){
        bool board[50][50];
        bool vis[50][50];
        queue<pair<int,int>> Q;

        // 입력
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                cin >> board[i][j];
            fill(vis[i], vis[i]+w, false);
        }

        // BFS로 Flood Fill하며 영역 개수 세기
        int area = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                // 이미 탐색한 곳이거나 육지가 아니면 패스
                if(!board[i][j] || vis[i][j]) continue;
                area++;

                // BFS할 시작점 선정
                vis[i][j] = true;
                Q.emplace(i,j);
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int i = 0; i < 8; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0|| ny< 0|| nx >= h|| ny >= w) continue;
                        if(vis[nx][ny] || !board[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.emplace(nx,ny);
                    }
                }

            }
        }
        cout << area << '\n';
    }

    return 0;
}
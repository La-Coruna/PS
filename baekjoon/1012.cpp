/* 
[유기농 배추]
- date: 24.06.25
- 분류: BFS
*/

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, M, N, K; // T: 테스트 케이스, M:가로, N:세로, K:배추개수
    cin >> T;

    while(T--){
        bool board[52][52] = {};
        bool vis[52][52] = {};
        queue<pair<int,int>> Q;
        int answer = 0;

        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            board[x][y] = true;
        }

        for(int x = 0; x < M; x++){
            for(int y = 0; y < N; y++){
                if(board[x][y] && !vis[x][y]){
                    // 새로운 색칠할 지역을 찾음.
                    answer++;
                    vis[x][y] = true;
                    Q.push({x,y});

                    // Flood Fill
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                            if(vis[nx][ny] || !board[nx][ny]) continue;
                            vis[nx][ny] = true;
                            Q.push({nx,ny});
                            K--;
                        }
                    }
                }
                if(K == 0) break; // 배추 다 찾으면 조기 종료
            }
        }
        cout << answer << "\n";        
    }
    return 0;
}
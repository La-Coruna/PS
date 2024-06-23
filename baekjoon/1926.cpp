/* 
[그림]
- date: 24.06.22
- 분류: BFS
*/
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int maxArea = 0; // 넓이
    int num = 0; // 개수
    int n,m;

    int board[505][505] = {0,};
    bool vis[505][505] = {false};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int,int>> Q;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || !board[i][j]) continue;
            vis[i][j] = 1;
            Q.push({i,j});
            num++;

            int area = 0;
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                area++;
                //cout << '(' << cur.X << ", " << cur.Y << ") -> ";
                for(int d = 0; d < 4; d++){
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
            maxArea = max(area,maxArea);
        }
    }

    cout << num << "\n" << maxArea;

    return 0;
}
/*
[보물섬] 
- date: 26.03.28 
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[50];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int L, W;
    cin >> L >> W;

    for(int i = 0; i < L; i++){
        cin >> board[i];
    }

    queue<pair<int,int>> Q;
    int max_dist = 0;

    for(int i = 0; i < L; i++){
        for(int j = 0; j < W; j++){
            int vis[50][50];
            for(int l = 0; l < L; l++)
                fill(vis[l], vis[l]+50, -1);

            if(board[i][j] == 'W') continue;

            vis[i][j] = true;
            Q.emplace(i,j);

            while(!Q.empty()){
                auto [x, y] = Q.front();
                Q.pop();

                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || ny < 0 || nx >= L || ny >= W) continue;
                    if(vis[nx][ny] != -1 || board[nx][ny] == 'W') continue;
                    vis[nx][ny] = vis[x][y] + 1;
                    Q.emplace(nx,ny);
                    max_dist = max(max_dist, vis[nx][ny]);
                }
            }
        }
    }

    cout << max_dist - 1;

    return 0;
}
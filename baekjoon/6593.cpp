/* 
[상범 빌딩]
- date: 24.07.23
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        string board[30][30];
        int vis[30][30][30] = {0};
        queue<tuple<int,int,int>> Q;
        bool isEscaped = false;
        int answer = 0;

        int L, R, C;
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                cin >> board[i][j];
                // 시작지점 찾기
                for(int k = 0; k < C; k++){
                    if(board[i][j][k] == 'S') {
                        Q.push(make_tuple(i,j,k));
                        vis[i][j][k] = 1; // 시작점이 1임을 유의.
                    }
                }
            }
        }

        while(!Q.empty()){
            tuple<int,int,int> cur = Q.front(); Q.pop();
            int curVis = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
            for(int d = 0; d < 6; d++){
                int nx = get<0>(cur) + dx[d];
                int ny = get<1>(cur) + dy[d];
                int nz = get<2>(cur) + dz[d];
                if(nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
                if(vis[nx][ny][nz] > 0 || board[nx][ny][nz] == '#') continue;
                if(board[nx][ny][nz] == 'E'){isEscaped = true; answer = curVis; break;}
                vis[nx][ny][nz] = curVis + 1;
                Q.push(make_tuple(nx,ny,nz));
            }
            if(isEscaped) break;
        }
        

        if(isEscaped) cout << "Escaped in "<< answer << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}

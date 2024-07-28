/* 
[빙산]
- date: 24.07.27
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, answer = 0;
int board[310][310];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int BFS(){
    int areaCount = 0;
    bool vis[310][310] = {0};
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            areaCount++;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int d = 0; d < 4; d++){
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if(nx < 1 || ny < 1 || nx >= N-1 || ny >= M-1) continue;
                    if(vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return areaCount;
}

void Melt(){
    bool isMelted[300][300] = {0};
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            for(int d = 0; d < 4; d++){
                // 현재 지역이 바다면 pass
                if(board[i][j] == 0) break;
                int nx = i+dx[d];
                int ny = j+dy[d];
                // 인근 지역이 바다면 높이 1 감소
                if(board[nx][ny] == 0 && !isMelted[nx][ny]) {
                    isMelted[i][j] = 1;
                    board[i][j]--;
                }
            }
        }
    }
    ;
}

void PrintBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    while(true){
        int areaCount = BFS();
        if(areaCount == 0){
            cout << 0;
            break;
        }
        if(areaCount > 1){
            cout << answer;
            break;
        }
        Melt();
        answer++;
        // PrintBoard();
        // cout << '\n';
    }

    return 0;
}
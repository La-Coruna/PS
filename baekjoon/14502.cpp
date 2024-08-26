/* 
[연구소]
- date: 24.08.25
- 분류: BFS, Brute Force
- 벽을 세울 수 있는 절묘한 방법이 있을 줄 알았는데, 도저히 모르겠어서 풀이를 찾아보니, 백트래킹으로 푸는 문제더라. 이런.
- 시간 복잡도에 대한 감이 없어서, 설마 백트랙킹일까 싶었나보다.
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// (3 ≤ N, M ≤ 8)
int N, M;
int board[8][8];
bool vis[8][8];
queue<pair<int,int>> Q;
vector<pair<int,int>> virus;

int totalArea = 0;
int virusArea = 0;
int wallArea = 0;
int maxSafeArea = 0;

void BFS(){
    virusArea = 0;
    for(int i = 0; i < N; i++){
        fill(vis[i], vis[i]+M, false);
    }
    for(auto v: virus){
        Q.push(v);
        virusArea++;
        vis[v.X][v.Y] = true;
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(vis[nx][ny]||board[nx][ny] == 1) continue;
            vis[nx][ny] = true;
            Q.push({nx,ny});
            virusArea++;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    totalArea = N*M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i,j});
            else if(board[i][j] == 1) wallArea++;
        }
    }

    wallArea += 3; // 벽 3개 추가
    for(int i = 0; i < N*M; i++){
        int wall1_x = i / M, wall1_y = i % M;
        if(board[wall1_x][wall1_y] != 0) continue;
        board[wall1_x][wall1_y] = 1;
        for(int j = i+1; j < N*M; j++){
            int wall2_x = j / M, wall2_y = j % M ;
            if(board[wall2_x][wall2_y] != 0) continue;
            board[wall2_x][wall2_y] = 1;
            for(int k = j+1; k < N*M; k++){
                int wall3_x = k / M, wall3_y = k % M;
                if(board[wall3_x][wall3_y] != 0) continue;
                board[wall3_x][wall3_y] = 1;
                BFS();
                maxSafeArea = max(maxSafeArea, totalArea - virusArea - wallArea);
                board[wall3_x][wall3_y] = 0;
            }
            board[wall2_x][wall2_y] = 0;
        }
        board[wall1_x][wall1_y] = 0;
    }

    cout << maxSafeArea;

    return 0;
}
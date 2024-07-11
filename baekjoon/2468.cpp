/* 
[안전 영역]
- date: 24.07.04
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
bool issuedHeight[100];
int heightArr[100];
int heightNum = 0;
int areaNum[100]; // 해당 높이의 영역의 개수
int board[103][103];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;
int maxAreaNum = 1;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){ 
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(!issuedHeight[board[i][j]]){
                issuedHeight[board[i][j]] = 1;
                heightArr[heightNum++] = board[i][j];
            }
        }
    }
    sort(heightArr,heightArr + heightNum);
    for(int a = 0; a < heightNum; a++){
        bool vis[103][103] = {};

        int curHeight = heightArr[a];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(vis[i][j]) continue;
                if(board[i][j] <= curHeight) continue;
                maxAreaNum = max(maxAreaNum,++areaNum[curHeight]);
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0||ny < 0||nx >= N||ny >= N) continue;
                        if(vis[nx][ny] || board[nx][ny] <= curHeight) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }    
            }
        }
    }

    cout << maxAreaNum;
    return 0;
}
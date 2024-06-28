/* 
[단지번호붙이기]
- date: 24.06.28
- 분류: BFS
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[30][30];
string board[30];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int areaNum = 0;
    int areaSize[900] = {};
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(board[x][y] == '0' || vis[x][y]) continue;
            vis[x][y] = true;
            Q.push({x,y});
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                areaSize[areaNum]++;
                for(int i = 0; i < 4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx<0||ny<0||nx>=N||ny>=N) continue;
                    if(vis[nx][ny] || board[nx][ny] == '0') continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
            areaNum++;
        }
    }
    cout << areaNum << '\n';
    sort(areaSize, areaSize+areaNum);
    for(int i = 0; i < areaNum; i++)
        cout << areaSize[i] << '\n';
    return 0;
}
/* 
[적록색약]
- date: 24.06.25
- 분류: BFS
*/
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

string board[101];
bool vis[101][101];
bool visCW[101][101];
queue<pair<int,int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int numOfArea = 0;
    int numOfAreaRG = 0;

    cin >> N;
    for(int x = 0; x < N; x++){
        cin >> board[x];
    }

    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            // 색약 X
            if(!vis[x][y]){
                char curColor = board[x][y];
                numOfArea++;
                vis[x][y] = true;
                Q.push({x,y});
                
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if(vis[nx][ny] || board[nx][ny] != curColor) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
            // 색약 O
            if(!visCW[x][y]){
                // RG
                if( board[x][y] != 'B'){
                    numOfAreaRG++;
                    visCW[x][y] = true;
                    Q.push({x,y});
                    
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if(visCW[nx][ny] || board[nx][ny] == 'B') continue;
                            visCW[nx][ny] = true;
                            Q.push({nx,ny});
                        }
                    }
                }
                // B
                else{
                    numOfAreaRG++;
                    visCW[x][y] = true;
                    Q.push({x,y});
                    
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if(visCW[nx][ny] || board[nx][ny] != 'B') continue;
                            visCW[nx][ny] = true;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
            
        }
    }
    cout << numOfArea << " " << numOfAreaRG;
    return 0;
}
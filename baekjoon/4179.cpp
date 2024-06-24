/* 
[불!]
- date: 24.06.24
- 분류: BFS

- 실수: 불이 아직 도착 안해서 0인 건데, 이 값과 지훈이 이동시간과 비교해서, 불이 더 빨리 도착했다고 비교했었음.
 */
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

string board[1001];
int distJ[1001][1001];
int distF[1001][1001];
queue<pair<int,int>> QJ;
queue<pair<int,int>> QF;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        cin >> board[i];
        for(int j = 0; j < C; j++){
            if (board[i][j] == 'J'){
                distJ[i][j] = 1;
                QJ.push({i,j});
            }
            else if (board[i][j] == 'F'){
                distF[i][j] = 1;
                QF.push({i,j});
            }
        }
    }

    while(!QF.empty()){
        pair<int,int> cur = QF.front(); QF.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(distF[nx][ny] > 0 || board[nx][ny] != '.') continue;
            distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            QF.push({nx,ny});
        }
    }

    while(!QJ.empty()){
        pair<int,int> cur = QJ.front(); QJ.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(distJ[nx][ny] > 0 || board[nx][ny] != '.') continue;
            int nDistJ = distJ[cur.X][cur.Y] + 1;
            if(distF[nx][ny] > 0 && nDistJ >= distF[nx][ny]) continue;
            distJ[nx][ny] = nDistJ;
            QJ.push({nx,ny});
        }
    }

    int minDistJ = 2000;
    for(int i = 0; i < C; i++){
        if(distJ[0][i] > 0)
            minDistJ = min(minDistJ, distJ[0][i]);
        if(distJ[R-1][i] > 0)
            minDistJ = min(minDistJ, distJ[R-1][i]);
    }
    for(int i = 0; i < R; i++){
        if(distJ[i][0] > 0)
            minDistJ = min(minDistJ, distJ[i][0]);
        if(distJ[i][C-1] > 0)
            minDistJ = min(minDistJ, distJ[i][C-1]);
    }

    // cout << "<Board>\n";
    // for(int i = 0; i < R; i++){
        
    //         cout << board[i];
        
    //         cout << '\n';
    // }

    // cout << "<Jihun>\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout << distJ[i][j] << ' ';
    //     }
    //         cout << '\n';
    // }

    // cout << "<fire>\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout << distF[i][j] << ' ';
    //     }
    //         cout << '\n';
    // }

    if (minDistJ == 2000)
        cout << "IMPOSSIBLE";
    else
        cout << minDistJ;
    return 0;
}
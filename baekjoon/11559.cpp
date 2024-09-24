/* 
[Puyo Puyo]
- date: 24.09.21
- 분류: Simulation
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[12];

int renCnt = 0;

bool FindRen(){
    bool hasRen = false;
    queue<pair<int,int>> Q;
    bool vis[12][6];

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j] == '.'||vis[i][j]) continue;
            // reset vis
            for(int i = 0; i < 12; i++)
                fill(vis[i], vis[i]+6, false);

            // init var
            vector<pair<int,int>> V;
            int cnt = 1;
            char curColor = board[i][j];
            vis[i][j] = true;
            Q.emplace(i,j);
            V.emplace_back(i,j);

            // flood fill
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int d = 0; d < 4; d++){
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];
                    if(nx<0||ny<0||nx>=12||ny>=6) continue;
                    if(vis[nx][ny]||board[nx][ny]!=curColor) continue;
                    vis[nx][ny] = true;
                    Q.emplace(nx,ny);
                    V.emplace_back(nx,ny);
                    cnt++;
                }
            }
            // if there is Ren
            if(cnt >= 4){
                for(auto v: V)
                    board[v.X][v.Y] = '0';
                hasRen = true;
            }
        }
    }
    
    return hasRen;
}

void UpdateBoard(){
    // except top
    for(int j = 5; j >= 0; j--){
        for(int i = 11; i >= 1; i--){
            if(board[i][j] != '0') continue;
            if(board[i][j] == '.') break;
            int upIdx = i-1;
            while(board[upIdx][j] == '0' && upIdx > 0){
                upIdx--;
            }
            board[i][j] = board[upIdx][j];
            board[upIdx][j] = '0';
        }
    }
    // top
    for(int j = 5; j >= 0; j--){
        int i = 0;
        while(true){
            if(board[i][j] != '0') break;
            board[i++][j] = '.';
        }
    }
    return;
}

void PrintBoard(){
    for(int i = 0; i < 12; i++)
        cout << board[i] << '\n';
    cout << '\n';
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++)
        cin >> board[i];

    while(true){
        // check if there is Ren
        bool hasRen = FindRen();
        if(!hasRen)
            break;

        renCnt++;
        
        UpdateBoard();
        //PrintBoard();
    }

    cout << renCnt;

    return 0;
}
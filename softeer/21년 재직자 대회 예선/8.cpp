/*
[21년 재직자 대회 예선] 이미지 프로세싱
- date: 24.09.29
- url: https://softeer.ai/class/devcrew/study/resource/detail/submission/6265?id=280&resourceId=328
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int H, W, board[129][129], Q;

void flood_fill(int x, int y, int c){
    int colorToFind = board[x][y];
    if(colorToFind == c) return;
    
    queue<pair<int,int>> Q;
    bool vis[129][129];
    for(int i = 1; i < 129; i++)
        fill(vis[i],vis[i]+129,false);
    
    vis[x][y] = true;
    Q.emplace(x,y);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        board[cur.X][cur.Y] = c;
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 1||ny < 1||nx >= 129||ny >= 129) continue;
            if(vis[nx][ny] || board[nx][ny] != colorToFind) continue;
            vis[nx][ny] = true;
            Q.emplace(nx,ny);
        }
    }
}

void printBoard(){
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++)
            cin >> board[i][j];
    }

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int x, y, c;
        cin >> x >> y >> c;
        flood_fill(x,y,c);
    }

    printBoard();

    return 0;
}
/* 
[로봇 청소기]
- date: 24.09.12
- 분류: simulation
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, d, r, c, cnt = 0;
bool board[50][50];
bool isClean[50][50];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M>> r >> c >> d;
    if(d == 1) d = 3;
    else if(d == 3) d = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    pair<int,int> cur = {r,c};
    while(true){
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(!isClean[cur.X][cur.Y]){
            isClean[cur.X][cur.Y] = true;
            cnt++;
        }
        
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        bool is4wayDirty = false;
        for(int i = 1; i <= 4; i++){
            int nd = (d+i)%4;
            int nx = cur.X + dx[nd];
            int ny = cur.Y + dy[nd];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(isClean[nx][ny]||board[nx][ny]==1)continue;
            cur = {nx,ny};
            is4wayDirty = true;
            d = nd;
            break;
        }
        
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if(!is4wayDirty){
            int back_direction = (d+2)%4;
            int nx = cur.X + dx[back_direction];
            int ny = cur.Y + dy[back_direction];
            if(nx<0||ny<0||nx>=N||ny>=M || board[nx][ny] == 1) {
                break;
            }
            cur = {nx,ny};
        }
    }

    cout << cnt;

    return 0;
}
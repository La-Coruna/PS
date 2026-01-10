/*
[미세먼지 안녕!] 
- date: 26.01.10
*/
#include <bits/stdc++.h>
using namespace std;

int air_purifier_top, air_purifier_bot;
int R, C, T, board[50][50], board_delta[50][50];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void reset_board_delta(){
    for(int i = 0; i < R; i++)
        fill(board_delta[i], board_delta[i] + C, 0);
    return;
}

void apply_board_delta(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            board[i][j] += board_delta[i][j];
        }
    }
    return;
}

void diffuse(int x, int y){
    int density = board[x][y];
    int diff_amount = density / 5;
    int diff_cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if(ny == 0 && (nx == air_purifier_top || nx == air_purifier_bot)) continue; // 공기 청정기 칸이면 pass
        diff_cnt++;
        board_delta[nx][ny] += diff_amount; // board_delta는 잘 초기화해서 써야 함.
    }
    board_delta[x][y] -= diff_amount * diff_cnt;
    return;
}

void diffuse_all_board(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            diffuse(i,j);
        }
    }
    return;
}

void purify(){
    // 윗 부분
    // ↓
    for(int x = air_purifier_top-1; x-1 >= 0; x--){
        board[x][0] = board[x-1][0];
    }
    // ←
    for(int y = 0; y+1 < C; y++){
        board[0][y] = board[0][y+1];
    }
    // ↑
    for(int x = 0; x+1 <= air_purifier_top; x++){
        board[x][C-1] = board[x+1][C-1];
    }
    // →
    for(int y = C-1; y-1 > 0; y--){
        board[air_purifier_top][y] = board[air_purifier_top][y-1];
    }
    board[air_purifier_top][1] = 0;
    // 아래 부분
    // ↑
    for(int x = air_purifier_bot+1; x+1 < R; x++){
        board[x][0] = board[x+1][0];
    }
    // ←
    for(int y = 0; y+1 < C; y++){
        board[R-1][y] = board[R-1][y+1];
    }
    // ↓
    for(int x = R-1; x-1 >= air_purifier_bot; x--){
        board[x][C-1] = board[x-1][C-1];
    }
    // →
    for(int y = C-1; y-1 > 0; y--){
        board[air_purifier_bot][y] = board[air_purifier_bot][y-1];
    }
    board[air_purifier_bot][1] = 0;
    return;
}

int get_all_dust(){
    int res = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            res += board[i][j];
        }
    }
    return res+2; // 공기청정기 값 제거
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // board 입력
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    // 공기 청정기 위치
    for(int i = 0; i < R; i++){
        if(board[i][0] == -1) {
            air_purifier_top = i;
            air_purifier_bot = i+1;
            break;
        }
    }

    // 1초 루틴 반복
    while(T--){
        // 1. 먼지 확산
        reset_board_delta();
        diffuse_all_board();
        apply_board_delta();

        // 2. 공기 청정
        purify();
    }
    
    cout << get_all_dust();

    return 0;
}
/*
[주사위 굴리기] 
- date: 25.01.29
- 분류: simulation
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 동1 서2 북3 남4 
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

int N, M, x, y, K;
int board[20][20];

int dice[7];

void MoveE(){
    int tmp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = tmp;
    return;
}
void MoveW(){
    int tmp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = tmp;
    return;
}
void MoveN(){
    int tmp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = tmp;
    return;
}
void MoveS(){
    int tmp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = tmp;
    return;
}

void RollDice(int dir){
    if(dir == 1) MoveE();
    else if(dir == 2) MoveW();
    else if(dir == 3) MoveN();
    else if(dir == 4) MoveS();
    return;
}

void CopyNum(int x, int y){
    if(board[x][y] == 0){
        board[x][y] = dice[6];
    } else{
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    int dir;
    for(int i = 0; i < K; i++){
        cin >> dir;

        // 주사위 좌표 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        x = nx;
        y = ny;

        // 주사위 회전
        RollDice(dir);

        // 지도랑 숫자 복사
        CopyNum(x,y);

        // 윗면 출력
        cout << dice[1] << '\n';
    }

    return 0;
}
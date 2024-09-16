/* 
[테트로미노]
- date: 24.09.16
- 분류: Backtracking, Brute Force
 */
#include <bits/stdc++.h>
using namespace std;

int board[500][500];
int N, M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int sum = 0;
int max_sum = 0;

int debug[4];

void func(int k, int x, int y, int prev_direction){
    if(k == 3){
        max_sum = max(max_sum, sum);
        return;
    }
    if(k == 0) sum = board[x][y];
    for(int i = 0; i < 4; i++){
        if(i == prev_direction) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0||ny < 0||nx >= N||ny >= M) continue;
        sum += board[nx][ny];
        func(k+1, nx, ny, (i+2)%4);
        sum -= board[nx][ny];
    }
}

void funcT(int x, int y){
    for(int t = 0; t < 4; t++){
        int tSum = board[x][y];
        for(int i = 0; i < 4; i++){
            if(i==t) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0||ny < 0||nx >= N||ny >= M) continue;
            tSum += board[nx][ny];
        }
        max_sum = max(max_sum, tSum);
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            func(0, i, j, -1);
            funcT(i,j);
        }
    }

    cout << max_sum;

    return 0;
}
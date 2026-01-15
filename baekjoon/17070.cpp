/*
[파이프 옮기기 1] 
- date: 26.01.15

dp[r][c][s]: 끝지점이 r행 c열에 있고 상태가 S일 때까지의 경우의 수
s = (0: 가로, 1: 세로, 2: 대각선)

- (가로) dp[r][c][0] = dp[r][c-1][0] + dp[r][c-1][2]
- (세로) dp[r][c][1] = dp[r-1][c][1] + dp[r-1][c][2]
- (대각) dp[r][c][2] = dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2]

*/
#include <bits/stdc++.h>
using namespace std;

int N;
bool board[17][17];
int dp[17][17][3]; // 0: 가로, 1: 세로, 2: 대각선

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    // 시작 위치
    dp[1][2][0]++;

    // 첫 행
    for(int c = 3; c <= N; c++){
        if(!board[1][c]) dp[1][c][0] = dp[1][c-1][0];
    }

    for(int r = 2; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(!board[r][c]) dp[r][c][0] = dp[r][c-1][0] + dp[r][c-1][2];
            if(!board[r][c]) dp[r][c][1] = dp[r-1][c][1] + dp[r-1][c][2];
            if(!(board[r][c]||board[r-1][c]||board[r][c-1])) dp[r][c][2] = dp[r-1][c-1][0] + dp[r-1][c-1][1] + dp[r-1][c-1][2];
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];

    return 0;
}
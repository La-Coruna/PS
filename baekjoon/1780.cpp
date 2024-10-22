/* 
[종이의 개수]
- date: 24.10.22
- 분류: recursion
 */
#include <bits/stdc++.h>
using namespace std;

int board[2187][2187];
int answer[3];

void func(int x, int y, int N){
    int firstPiece = board[x][y];
    if(N != 1){
        for(int i = x; i < x + N; i++){
            for(int j = y; j < y + N; j++){
                if(firstPiece != board[i][j]) {
                    int d = N/3;
                    for(int a = 0; a < 3; a++){
                        for(int b = 0; b < 3; b++){
                            func(x+a*d, y+b*d, d);
                        }
                    }
                    return; 
                }
            }
        }
    }

    if(firstPiece == -1) answer[0]++;
    else if(firstPiece == 0) answer[1]++;
    else if(firstPiece == 1) answer[2]++;
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    func(0,0,N);
    for(int ans : answer)
        cout << ans << '\n';

    return 0;
}
/* 
[색종이 만들기]
- date: 24.09.08
- 분류: recursion
 */

#include <bits/stdc++.h>
using namespace std;

// 파랑 true, 하양 false
bool board[128][128];
int blue = 0, white = 0;

void func(int k, int x, int y){
    bool c = board[x][y];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(board[x+i][y+j] != c){
                func(k/2, x, y);
                func(k/2, x + k/2, y);
                func(k/2, x, y + k/2);
                func(k/2, x + k/2, y + k/2);
                return;
            }
        }
    }
    if(c) blue++;
    else white++;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    func(N, 0, 0);
    cout << white << '\n' << blue;

    return 0;
}
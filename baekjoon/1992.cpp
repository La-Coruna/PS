/* 
[쿼드트리]
- date: 24.09.12
- 분류: recursion
 */

#include <bits/stdc++.h>
using namespace std;
string board[64];

void func(int n, int x, int y){
    if(n==1){
        cout << board[x][y];
        return;
    }
    char first = board[x][y];
    bool a = false;
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(first != board[i][j]) {
                a = true;
                break;
            }
        }
        if(a) break;
    }
    if(a) {
        cout << '(';
        func(n/2, x, y);
        func(n/2, x, y+n/2);
        func(n/2, x+n/2, y);
        func(n/2, x+n/2, y+n/2);
        cout << ')';
    } else{
        cout << first;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    func(N,0,0);

    return 0;
}
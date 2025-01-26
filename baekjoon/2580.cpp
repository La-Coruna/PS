/*
[스도쿠] 
- date: 25.01.26
- 분류: backtracking
*/
#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int>> V;

bool rowNums[9][10];
bool colNums[9][10];
bool sqrNums[3][3][10];

bool IsExistedNum(int x, int y, int num){
    return (rowNums[x][num] || colNums[y][num] || sqrNums[x/3][y/3][num]);
}

void EnterNum(int x, int y, int num){
    board[x][y] = num;
    rowNums[x][num] = true;
    colNums[y][num] = true;
    sqrNums[x/3][y/3][num] = true;
    return;
}

void UndoEnterNum(int x, int y, int num){
    rowNums[x][num] = false;
    colNums[y][num] = false;
    sqrNums[x/3][y/3][num] = false;
    return;
}

bool bruteForce(int k){
    if(k==V.size()) return true;

    int x, y;;
    tie(x,y) = V[k];

    for(int num = 1; num <= 9; num++){
        if(IsExistedNum(x, y, num)) continue;
        EnterNum(x, y, num);
        if(bruteForce(k+1)) return true;
        UndoEnterNum(x, y, num);
    }

    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                V.emplace_back(i,j);
            } else{
                rowNums[i][board[i][j]] = true;
                colNums[j][board[i][j]] = true;
                sqrNums[i/3][j/3][board[i][j]] = true;
            }
        }
    }

    bruteForce(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
/* 
[2048 (Easy)]
- date: 24.07.21
- 분류: Simulation
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int board[20][20];
int answer = 0;

void Left(){
    for(int i = 0; i < N; i++){
        int tmp[20] = {0};
        int k = 0;
        int cur = board[i][0];
        for(int j = 1; j < N; j++){
            if(cur == 0) {cur = board[i][j];}
            else if (board[i][j] == 0) {
                continue;
            }
            else if(cur == board[i][j]) {
                tmp[k++] = cur * 2;
                cur = 0;
            }
            else {
                tmp[k++] = cur;
                cur = board[i][j];
            }
        }
        tmp[k] = cur;
        for(int j = 0; j < N; j++){
            board[i][j] = tmp[j];
        }
    }
}
void Right(){
    for(int i = 0; i < N; i++){
        int tmp[20] = {0};
        int k = 0;
        int cur = board[i][N-1];
        for(int j = N-2; j >= 0; j--){
            if(cur == 0) {cur = board[i][j];}
            else if (board[i][j] == 0) {
                continue;
            }
            else if(cur == board[i][j]) {
                tmp[k++] = cur * 2;
                cur = 0;
            }
            else {
                tmp[k++] = cur;
                cur = board[i][j];
            }
        }
        tmp[k] = cur;
        for(int j = 0; j < N; j++){
            board[i][j] = tmp[N-j-1];
        }
    }
}
void Up(){
    for(int j = 0; j < N; j++){
        int tmp[20] = {0};
        int k = 0;
        int cur = board[0][j];
        for(int i = 1; i < N; i++){
            if(cur == 0) {cur = board[i][j];}
            else if (board[i][j] == 0) {
                continue;
            }
            else if(cur == board[i][j]) {
                tmp[k++] = cur * 2;
                cur = 0;
            }
            else {
                tmp[k++] = cur;
                cur = board[i][j];
            }
        }
        tmp[k] = cur;
        for(int i = 0; i < N; i++){
            board[i][j] = tmp[i];
        }
    }
}
void Down(){
    for(int j = 0; j < N; j++){
        int tmp[20] = {0};
        int k = 0;
        int cur = board[N-1][j];
        for(int i = N-2; i >= 0; i--){
            if(cur == 0) {cur = board[i][j];}
            else if (board[i][j] == 0) {
                continue;
            }
            else if(cur == board[i][j]) {
                tmp[k++] = cur * 2;
                cur = 0;
            }
            else {
                tmp[k++] = cur;
                cur = board[i][j];
            }
        }
        tmp[k] = cur;
        for(int i = 0; i < N; i++){
            board[i][j] = tmp[N-i-1];
        }
    }
}

void PrintBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void UpdateAnswer(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            answer = max(answer,board[i][j]);
        }
    }
}

void PlayGame(int trial){
    if(trial == 5) {
        UpdateAnswer();
        return;
    }

    int tmpBoard[20][20] = {0};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmpBoard[i][j] = board[i][j];
        }
    }

    Left();
    PlayGame(trial+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = tmpBoard[i][j];
        }
    }

    Right();
    PlayGame(trial+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = tmpBoard[i][j];
        }
    }

    Up();
    PlayGame(trial+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = tmpBoard[i][j];
        }
    }

    Down();
    PlayGame(trial+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = tmpBoard[i][j];
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    PlayGame(0);

    cout << answer;

    return 0;
}
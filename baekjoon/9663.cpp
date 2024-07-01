/* 
[N-Queen]
- date: 24.07.01
- 분류: Backtracking
- 대각선 체크를 위해 pair<int,int>를 이용해 O(N)으로 순회하였는데, 그것보다 issued배열로 O(1)로 접근해 체크하는 방법이 있다.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N;
bool issued1[15];
bool issued2[32];
bool issued3[32];
int answer = 0;

// 해설 보고 짠 코드
void func(int k){
    if(k == N){
        answer++;
        return;
    }
    // (k,i)에 퀸을 놓을 수 있는지 확인하고 넣음.
    for(int i = 0; i < N; i++){
        if(issued1[i]||issued2[k+i]||issued3[k-i+N-1]) continue;
        issued1[i] = true;
        issued2[k+i] = true;
        issued3[k-i+N-1] = true;
        func(k+1);
        issued1[i] = false;
        issued2[k+i] = false;
        issued3[k-i+N-1] = false;
    }
    return;
}

// 처음 짠 코드
/*
pair<int,int> position[15];
bool column[15];
void func(int k){
    if(k == N){
        answer++;
        return;
    }
    // (k,i)에 퀸을 놓을 수 있는지 확인하고 넣음.
    for(int i = 0; i < N; i++){
        // 열 체크
        if(column[i]) continue;
        // 대각선 체크
        bool isDiagonalFine = true;
        for(int j = 0; j < k; j++){
            if(k - position[j].X == abs(i - position[j].Y)){
                isDiagonalFine = false;
                break;
            }
        }
        if(!isDiagonalFine) continue;
        column[i] = true;
        position[k] = {k,i};
        func(k+1);
        column[i] = false;
    }
    return;
} */

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(0);
    cout << answer;
    return 0;
}
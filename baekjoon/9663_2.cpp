/* 
[N-Queen]
- date: 25.02.04
- 분류: backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;
bool col[15];
bool diagDiff[29];
bool diagSum[29];

void func(int row){
    if(row == N){
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(col[i] || diagDiff[row - i + N - 1] || diagSum[row + i - (N - 1)]) continue;
        col[i] = true;
        diagDiff[row - i + N - 1] = true;
        diagSum[row + i - (N - 1)] = true;
        func(row+1);
        col[i] = false;
        diagDiff[row - i + N - 1] = false;
        diagSum[row + i - (N - 1)] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    func(0);
    cout << cnt;

    return 0;
}
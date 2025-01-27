/*
[이항 계수 2] 
- date: 25.01.27
- 분류: DP
- 그냥 곱과 나누기로 풀면, 곱이 너무 커져서 자료형의 크기를 초과하거나, 약분을 세세하게 신경써줘야 함.
- nCk = n-1Ck-1 + n-1Ck
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10'007;
    }

    cout << dp[N][K];

    return 0;
}
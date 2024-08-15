/* 
[1, 2, 3 더하기 3]
- date: 24.08.15
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;

int T, n[1'000'000];
long long dp[1'000'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n[i];
    }

    int mx_n = *max_element(n, n+T);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= mx_n; i++){
        dp[i] = (dp[i-1] + dp[i-2]+ dp[i-3]) % 1'000'000'009;
    }

    for(int i = 0; i < T; i++){
        cout << dp[n[i]] << '\n';
    }

    return 0;
}

/* 
dp[1] = 1
dp[2] = 2 : 1+1, 2
dp[3] = 4 : 1+1+1, 2+1, 1+2, 3
dp[4] = 7 : 1+1+1+1, 2+1+1, 1+2+1, 3+1 / 1+1+2, 2+2 /  1+3
dp[5] = ? : dp[4] / dp[3] / dp[2]

dp[n] = ? : dp[n-1] + dp[n-2] + dp[n-3]

 */
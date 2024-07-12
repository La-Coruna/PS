/* 
[1로 만들기]
- date: 24.07.11
- 분류: DP
 */
#include <bits/stdc++.h>

using namespace std;

int dp[1000003];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int X;
    cin >> X;
    dp[1] = 0;
    for(int i = 2; i <= X; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i/2] + 1, dp[i]);
        if(i%3 == 0) dp[i] = min(dp[i/3] + 1, dp[i]);
    }

    cout << dp[X];
    return 0;
}
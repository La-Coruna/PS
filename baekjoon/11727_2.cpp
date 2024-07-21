/* 
[2×n 타일링 2]
- date: 24.07.17
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-2] * 2 + dp[i-1])%10007;
    }
    cout << dp[n];

    return 0;
}
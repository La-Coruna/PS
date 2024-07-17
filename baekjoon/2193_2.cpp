/* 
[이친수]
- date: 24.07.17
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
long long dp[90][2];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for(int i = 2; i < n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[n-1][0] + dp[n-1][1];

    return 0;
}
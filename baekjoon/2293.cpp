/* 
[동전 1]
- date: 24.08.17
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, coin[100], dp[10'001];
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    fill(dp,dp+k+1,0);
    dp[0] = 1;
    for(int c = 0; c < n; c++){
        for(int i = coin[c]; i <= k; i++){
            dp[i] += dp[i-coin[c]];
        }

    }
    cout << dp[k];

    return 0;
}
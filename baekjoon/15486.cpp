/* 
[퇴사 2]
- date: 24.08.15
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1'500'053];
int T[1'500'003];
int P[1'500'003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> P[i];
    }
    for(int i = 1; i <= N; i++){
        dp[i] = max(dp[i], dp[i-1]);
        dp[i+T[i]-1] = max(dp[i+T[i]-1], dp[i-1] + P[i]);
    }
    cout << dp[N];
    return 0;
}
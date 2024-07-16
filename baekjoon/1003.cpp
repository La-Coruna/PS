/* 
[피보나치 함수]
- date: 24.07.16
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
pair<int,int> dp[41]; // N은 0 ~ 40
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    dp[0] = {1,0};
    dp[1] = {0,1};
    while(T--){
        int N;
        cin >> N;
        for(int i = 0; i <= N; i++){
            if(dp[i].first == 0 && dp[i].second == 0) {
                dp[i] = {dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second};
            }
        }
        cout << dp[N].first << ' ' << dp[N].second << '\n';
    }
    return 0;
}
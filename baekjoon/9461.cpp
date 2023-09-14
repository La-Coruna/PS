/* 
date: 0826
분야: dp
알고리즘:
N이 9부터, dp[N] = dp[N-1] + dp[N-5] 이다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,N;
    cin >> T;

    vector<long long> dp(101,0);
    dp[0]=1; // p(1) = dp[0]
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    dp[4]=2;
    dp[5]=3;
    dp[6]=4;
    dp[7]=5;
    dp[8]=7;
    dp[9]=9; // p(10) = dp[9]
    while(T--){
        cin >> N;
        if(!dp[N]){ 
            for(int i = 10; i < N; i++){
                dp[i] = dp[i-1] + dp[i-5];
            }
        }
        cout << dp[N-1] <<"\n";
    }

    return 0;
}
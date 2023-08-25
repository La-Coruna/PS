/* 
date: 0825
분야: dp
알고리즘:
N이 짝수라고 가정할 때,
dp[N] = 3*dp[N-2] + 2*dp[N-4] + ... + 2*dp[2] + 2
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if(N%2 != 0){
        cout << 0;
        return 0;
    }

    N /= 2;
    vector<int> dp(N+1);
    dp[1] = 3;
    for(int i = 2; i <= N; i++){
        dp[i] = 3*dp[i-1] + 2;
        for(int j = 1; j < i-1; j++){
            dp[i] += 2*dp[j];
        }
    }
    
    cout << dp[N];

    return 0;
}
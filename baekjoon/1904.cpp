/* 
[01타일]
- date: 0904
- 분류: dp
- 알고리즘: dp[i]는 만들 수 있는 i자리 숫자의 개수.
            dp[i] = dp[i-1] + dp[i-2] // i자리 숫자는 (i-1)자리 숫자 뒤에 '1'을 붙인 것과 (i-2)자리 숫자 뒤에 '00'을 붙인 것, 두 경우로만 이루어짐.

            <초기값>
            dp[1] = 1; // 1
            dp[2] = 2; // 00 11
            dp[3] = 3; // 100 001 111
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> dp(N+1,0);

    // N = 1, 2
    dp[1] = 1;          // (1)
    if(N>1) dp[2] = 2;  // (00) (11)

    // N > 3
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }

    cout << dp[N];

    return 0;
}
/* 
[암호코드]
- date: 0829
- 분류: dp
- 알고리즘:
    dp[i] => i번째까지의 암호가 해석될 수 있는 경우의 수

    1) arr[i]와 arr[i-1]이 두 개의 알파벳으로 해석될 경우 -> dp[i] = dp[i-1]
        - arr[i]가 0이 아닌 1~9까지의 숫자여야함.
    2) arr[i]와 arr[i-1]이 한 개의 알파벳으로 해석될 경우 -> dp[i] = dp[i-2]
    3) 1)과 2)가 모두 가능한 경우                        -> dp[i] = dp[i-1] + dp[i-2]
    4) 해석이 불가능한 경우                              -> dp[i] = 0

- 개선 사항: 1) 문자열로 입력을 받은 후, 숫자로 바꾸어 다루는 것이 가독성이 더 좋을 것이다.
            2) 작동 방식(논리)를 더 간결하게 할 수 있다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    int n = input.size();

    vector<int> arr(n+1, 0);
    vector<int> dp(n+1, 0);

    // input
    for(int i = 1; i < n+1; i++){
        arr[i] = input[i-1]-'0';
    }

    // solve
    dp[0] = 1; // 아래의 i=2일때, 2)의 경우 dp[i-2]로 1이 들어가기 위해.
    if(arr[1] == 0)
        dp[1] = 0;
    else
        dp[1] = 1;
    for(int i = 2; i < n+1; i++){
        // 1) arr[i]와 arr[i-1]이 두 개의 알파벳으로 해석될 경우
        if(arr[i] != 0)
            dp[i] = dp[i-1];

        //2) arr[i]와 arr[i-1]이 한 개의 알파벳으로도 해석될 경우
        int two_digit_num = arr[i-1]*10 + arr[i];
        if(two_digit_num >= 10 && two_digit_num <= 26)
            dp[i] = (dp[i] + dp[i-2])%1000000;
    }

    // 출력
    cout << dp[n];

    return 0;
}
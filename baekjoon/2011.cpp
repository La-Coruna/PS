/* 
[암호코드]
- date: 0829
- 분류: dp
- 알고리즘:
    dp[i-1] => i번째까지의 암호가 해석될 수 있는 경우의 수
    1) arr[n-1]이 1과 2(arr[n]<=6이면서)가 아니라면, dp[n] = dp[n-1]
    2) arr[n-1]이 1과 2(arr[n]<=6이면서)라면, 2-1) arr[n-2]가 1or2라면, dp[n-2]*2 + dp[n-3]
                                             2-2) 아니라면, dp[n-2]*2

- 주의 사항: 0은 10(J)과 20(T)으로 밖에 해석이 안됨.
            항상 해석될 수 있는 암호가 주어지는 것이 아님. ex) 0, 100, 40
- 오답 사유: 1) 놓친 반례들: 40, 19126
            2) 모듈러 까먹음
            3) 오타.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string code;
    cin >> code;

    int n = code.size();

    vector<int> dp(n, 0);

    // 1자리 이상
    // 존재하지 않는 암호의 경우의 예외처리.
    if(code[0] - '0' == 0){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    
    // 2자리 이상
    if(n >= 2){
        if(code[1] - '0' == 0){
            // 존재하지 않는 암호의 경우의 예외처리.
            if(code[0] - '1' != 0 && code[0] - '2' != 0){
                cout << 0;
                return 0;
            }
            dp[1] = 1;
        }
        else if(code[0] - '1' == 0 || (code[0] - '2' == 0 && code[1] - '6' <= 0))
            dp[1] = 2;
        else
            dp[1] = 1;
    }

    // 3자리 이상
    if(n >= 3){
        if(code[2] - '0' == 0){
            // 존재하지 않는 암호의 경우의 예외처리.
            if(code[1] - '1' != 0 && code[1] - '2' != 0){
                cout << 0;
                return 0;
            }
            dp[2] = 1;
        }
        else if(code[1] - '1' == 0 || (code[1] - '2' == 0 && code[1] - '6' <= 0)){
            if(code[0] - '1' == 0 || code[0] - '2' == 0 )
                dp[2] = 3;
            else    
                dp[2] = 2;
        } else
            dp[2] = dp[1];
    }

    // 4자리 이상
    for(int i = 3; i < n; i++){
        if(code[i] - '0' == 0){
            // 존재하지 않는 암호의 경우의 예외처리.
            if(code[i-1] - '1' != 0 && code[i-1] - '2' != 0){
                cout << 0;
                return 0;
            }
            dp[i] = dp[i-2];
        }
        else if(code[i-1] - '1' == 0 || (code[i-1] - '2' == 0 && code[i] - '6' <= 0)){
            if(code[i-2] - '1' == 0 || code[i-2] - '2' == 0 ){
                dp[i] = (dp[i-2]*2 + dp[i-3])%1000000;
            }
            else    
                dp[i] = (dp[i-2]*2)%1000000;
        }
        else
            dp[i] = dp[i-1];
    }

    // 출력
    cout << dp[n-1];

    return 0;
}
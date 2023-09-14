/* 
date: 0816
분야: dp
알고리즘: 자기보다 작은 값으로 끝난 증가하는 수열의 합과 비교해서 최대값 구함.
10, 20, 100, 30, 20, 50

10 (10,10)
10 20 (10,10) (20,30)
10 20 100 (10,10) (20,30) (100,130)
10 20 100 30 (10,10) (20,30) (100,130) (30,33)
10 20 100 30 20 (10,10) (20,30) (100,130) (30,33) | (20,30)
10 20 100 30 20 50 (10,10) (20,30) (100,130) (30,33) | (50,83)

소감: 11053 참고해서 조금만 수정.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[1000] = {0};
    int N;
    int input;
    int max_dp;

    cin >> N;

    cin >> input;
    dp[input] = input;
    max_dp = dp[input];
    for(int i = 1; i < N; i++){
        cin >> input;
        int max_dp_under_input = 0; // input 보다 작은 dp들 중 최대값
        for(int j = 0; j<input; j++){
            max_dp_under_input = max(max_dp_under_input, dp[j]);
        }
        dp[input] = max_dp_under_input+input;
        max_dp = max(max_dp,dp[input]);
    }
    cout << max_dp;

    return 0;    
}
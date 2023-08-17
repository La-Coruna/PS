/* 
date: 0816
분야: dp
알고리즘: 자기보다 큰 값으로 끝난 감소하는 수열의 길이와 비교해서 최대값 구함.
소감: 11053번을 풀고 그냥 그대로 복붙해와서 조건만 반대로 바꿔주니 해결.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int dp[1001] = {0};
    int N;
    int input;
    int max_dp;

    cin >> N;

    cin >> input;
    max_dp = ++dp[input];
    for(int i = 1; i < N; i++){
        cin >> input;
        int max_dp_over_input = 0; // input 보다 작은 dp들 중 최대값
        for(int j = 1000; j>input; j--){
            max_dp_over_input = max(max_dp_over_input, dp[j]);
        }
        dp[input] = max_dp_over_input+1;
        max_dp = max(max_dp,dp[input]);
    }
    cout << max_dp;

    return 0;    
}
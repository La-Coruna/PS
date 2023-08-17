/* 
date: 0816
분야: dp
알고리즘: 자기보다 작은 값으로 끝난 증가하는 수열의 길이와 비교해서 최대값 구함.
10, 20, 100, 30, 20, 50

10 (10,1)
10 20 (10,1) (20,2)
10 20 100 (10,1) (20,2) (100,3)
10 20 100 30 (10,1) (20,2) (100,3) (30,3)
10 20 100 30 20 (10,1) (20,2) (100,3) (30,3) | (20,2)
10 20 100 30 20 50 (10,1) (20,2) (100,3) (30,3) (50,4)

소감: 그냥 짰는데 되네. 이왜진?
다른 분들 것 참고하니, 입력 값을 배열로 저장해두고 비교할 때 이용하더라.
지금은 입력 값의 범위가 1000이하라 이렇게 짰는데, 입력 값의 범위가 넓어지면 그쪽이 훨씬 좋을 듯.

+ 변수를 짤 때 변수가 의미하는 것이 뭔지 정확하게 정의해두자.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int dp[1000] = {0};
    int N;
    int input;
    int max_dp;

    cin >> N;

    cin >> input;
    max_dp = ++dp[input];
    for(int i = 1; i < N; i++){
        cin >> input;
        int max_dp_under_input = 0; // input 보다 작은 dp들 중 최대값
        for(int j = 0; j<input; j++){
            max_dp_under_input = max(max_dp_under_input, dp[j]);
        }
        dp[input] = max_dp_under_input+1;
        max_dp = max(max_dp,dp[input]);
    }
    cout << max_dp;

    return 0;    
}

// 아래는 새로 짠 코드
/* 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, input, answer;
    vector<int> arr;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        arr.emplace_back(input);
    }
    vector<int> dp(N, 0); // dp[a]=b // a번째까지의 증가하는 수열의 최대 길이는 b이다.

    dp[0] = 1;
    answer = 1;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]);
            }
        }
        ++dp[i];
        answer = max(answer, dp[i]);
    }
    cout << answer;

    return 0;
}

 */
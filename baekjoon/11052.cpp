/* 
[카드 구매하기]
- date: 0830
- 분류: dp
- 알고리즘: '그' 막대기 문제. dp[0] + arr[i] ~ dp[i-1] + arr[1]
- 주의 사항: 인덱싱
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> arr(N+1,0);
    vector<int> dp(N+1,0);
    arr[0] = 0;
    dp[0] = 0;
    
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            dp[i] = max(dp[i], dp[j]+arr[i-j]);
            //dp[0] + arr[i] ~ dp[i-1] + arr[1]
        }
    }
    
    cout << dp[N];
    
    return 0;
}
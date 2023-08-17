/* 
[계단 오르기]
- date: 0817
- 분류: dp
- 알고리즘:
    i번째 계단을 밟았을 때 최대 점수 = 'i-3 밟고, i-2 건너뛰고, i-1 밟았을 때의 점수' 와 'i-2 밟았을 때의 점수' 중 큰 값 + i번째 점수
    dp[i] == i번째 계단을 밟았을 때 최대 점수

<case 1>
input:      10  20       15                   25 10  20
dp(answer): 10  30=10+20 35=max(10+15, 20+15) ...

- 시간복잡도: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, input;

    cin >> n;

    vector<int> dp(n,0);
    vector<int> arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(n==1){   
        cout << arr[0];
    } else if(n==2){
        cout << arr[0] + arr[1];
    } else{
        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max(arr[0] + arr[2],arr[1] + arr[2]);
        for(int i = 3; i < n; i++){ // case: n > 3
            dp[i] = max(dp[i-3] + arr[i-1], dp[i-2]) + arr[i];
        }
        cout << dp[n-1];
    }
    
    return 0;
}
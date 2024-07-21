/* 
[정수 삼각형]
- date: 24.07.17
- 분류: DP
- DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + arr[i][j]
 */
#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
int arr[500][500];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, answer;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0]; // 가장 왼쪽 경우
        dp[i][i] = dp[i-1][i-1] + arr[i][i]; // 가장 오른쪽 경우
        for(int j = 1; j < i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    answer = *max_element(dp[n-1], dp[n-1]+n);;
    cout << answer;

    return 0;
}
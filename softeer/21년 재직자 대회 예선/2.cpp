/* 
[21년 재직자 대회 본선] 비밀 메뉴2
- date: 24.09.09
- 분류: DP, LCS + continuous
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6259?id=280&resourceId=328
 */
#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    int A[3000], B[3000];
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    int answer = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(A[i-1] != B[j-1]) continue;
            dp[i][j] = dp[i-1][j-1] + 1;
            if(dp[i][j]>answer) answer = dp[i][j];
        }
    }

    cout << answer;

    return 0;
}
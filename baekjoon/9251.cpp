/* 
[LCS]
- date: 24.09.07
- 분류: DP, LCS

- D[i][j] : A[i-1]와 B[j-1]까지 비교했을 때의 LCS 길이.
- 두가지 경우
    - A[i-1] == B[j-1] -> D[i][j] = D[i-1][j-1] + 1
    - A[i-1] != B[j-1] -> D[i][j] = max(D[i-1][j], D[i][j-1])
        - AC'A'와 CA'P'를 비교할 때, A와 P가 다르기 때문에, 'AC와 CAP -> A(1)'의 경우와 'ACA와 CA -> AC(2)'의 경우 중 더 긴 전자를 선택해야함.
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;
 
    int len_A = A.length();
    int len_B = B.length();

    for(int i = 1; i <= len_A; i++){
        for(int j = 1; j <= len_B; j++){
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[len_A][len_B];

    return 0;
}
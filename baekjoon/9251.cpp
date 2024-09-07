/* 
[LCS]
- date: 24.09.07
- 분류: DP, LCS

- D[i][j] : A[i]와 B[j]까지 비교했을 때의 LCS 길이.
- 두가지 경우
    - A[i] == B[j] -> D[i][j] = D[i-1][j-1] + 1
    - A[i] != B[j] -> D[i][j] = max(D[i-1][j], D[i][j-1])
        - AC'A'와 CA'P'를 비교할 때, A와 P가 다르기 때문에, 'ACA와 CA -> AC(2)'의 경우와 'AC와 CAP -> A(1)'의 경우 중 더 긴 전자를 선택해야함.
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int A_len, B_len, dp[1001][1001];
    A_len = A.length();
    B_len = B.length();
    for(int i = 0; i <= A_len; i++){
        fill(dp[i], dp[i]+1+B_len, 0);
    }


    for(int i = 0; i < A_len; i++){
        for(int j = 0; j < B_len; j++){
            if(A[i] == B[j]) dp[i+1][j+1] = dp[i][j] +1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int lcs = 0;
    for(int i = 1; i <= A_len; i++){
        for(int j = 1; j <= B_len; j++){
            if(dp[i][j] > lcs) lcs = dp[i][j];
        }
    }

    cout << lcs;

    return 0;
}
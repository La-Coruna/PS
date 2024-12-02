/*
[3 x n 타일링]
- date: 24.12.01
- url: https://school.programmers.co.kr/learn/courses/30/lessons/12902

- dp[n/2] : 가로 길이가 n일때의 경우의 수
- dp[0] = 1
- dp[1] = 3
- dp[2] = dp[1] * 3 + 2(dp[0])
- dp[3] = dp[2] * 3 + 2(dp[0] + dp[1])
- dp[i] = dp[i-1] * 3 + 2(dp[0] + ... + dp[i-2])
*/
#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    if(n%2 == 1) return 0;
    int N = n/2;
    long long dp[2501] = {0};
    dp[0] = 1;
    dp[1] = 3;
    int sum = dp[0]*2;
    for(int i = 2; i <= N; i++){
        dp[i] = (((dp[i-1] * 3) % 1'000'000'007) + sum) % 1'000'000'007;
        sum = (sum + dp[i-1]*2) % 1'000'000'007;
    }
    
    return (int)dp[N];
}
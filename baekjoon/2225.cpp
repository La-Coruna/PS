/* 
[합분해]
date: 0827
분야: dp
알고리즘: '덧셈의 순서가 바뀐 경우 다른 경우로 센다' -> 다른 상자
같은 구슬 N개를 다른 상자 K개에 넣는 경우 (0도 포함이기 때문에 빈상자 허용) -> 중복 조합 (K)H(N) = (K+N-1)C(N)
(K+N-1)C(N) = (K+N-1)*...*(K+1-1)/n! or (K+N-1)C(K-1) = (K+N-1)*...*(N)/(k-1)!
combination은 코드 스니펫 이용.
*/
#include <iostream>
#include <vector>

using namespace std;

int combination(int n, int k) {
    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, k); j > 0; --j) {
            dp[j] = dp[j] + dp[j - 1] % 1000000000;
        }
    }

    return dp[k] % 1000000000;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N >> K;

    cout << combination(K+N-1,N);

    return 0;
}
/* 
[제곱수의 합]
- date: 0817
- 분류: dp
- 알고리즘:
    dp[i] = 숫자 i를 제곱수의 합으로 나타낼 때 최소 항의 개수

<case>
1 = 1                   !
2 = 1 1
3 = 1 1 1
4 = 4                   !
5 = 4 1
6 = 4 1 1
7 = 4 1 1 1
8 = 4 4
9 = 9                   !
10 = 9 1
11 = 9 1 1
12 = 4 4 4 = 9 1 1 1
13 = 9 4
14 = 9 4 1
15 = 9 4 1 1
16 = 16                 !

- 시간복잡도: O(n^2)
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n+1);

    dp[0]=0;
    dp[1]=1;
    for(int i = 2; i <= n; i++){
        // init
        dp[i] = i; 
        int j = 1;
        for(; j*j <= i; j++){
			dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];

    return 0;
}

/* 
    아래는 처음 짠 코드.
    아래로 짰을 때는 시간 36ms.
    이후 다른 사람의 코드 보고 개선 후 32ms로 줄음.

    dp[1]=1;
    for(int i = 2; i <= n; i++){
        // init
        dp[i] = i; 
        int j = 1;
        for(; j*j < i; j++){
            dp[i] = min( dp[j*j] + dp[i-j*j], dp[i] ) ;
        }
        if(j*j==i)
            dp[i]=1;
    }
 */
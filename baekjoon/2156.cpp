/* 
date: 0815
깨달음을 얻고 다시 짬 (근데 메모리랑 시간은 똑같게 나옴 ㅋㅋ)

n번째 잔을 안 마신다면, 그 때의 최대 값은 n-1잔까지의 최대 값.
n번째 잔을 마신다면, 그 때는 'n-2잔을 안 마시고 n-1잔을 마셨을 때의 최대 값'과 'n-1잔을 안 마셨을 때의 최대 값' 중 더 큰 값 + n번째 잔.
-> 'n-2잔을 안 마시고 n-1잔을 마셨을 때의 최대 값' = 'n-3잔까지의 최대 값+ n-1잔'
-> 'n-1잔을 안 마셨을 때의 최대 값' = 'n-2잔까지의 최대 값'
    -> n번째 최대값을 알기 위해 알아야 이전 결과 값: 1.안 마신다면) n-1잔까지의 최대 값  2.마신다면) n-3잔까지의 최대 값, n-2잔까지의 최대 값
    -> n번째 최대값: 1.안 마신다면) n-1잔까지의 최대 값  2.마신다면) max(n-3잔까지의 최대 값 + n-1잔 + n잔, n-2잔까지의 최대 값 + n잔)
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int *wine = new int[n+1];
    for(int i = 1; i < n+1; i++){
        cin >> wine[i];
    }
    if(n == 1){
        cout << wine[1];
    } else if(n == 2){
        cout << wine[1]+wine[2];
    } else{
        int* dp = new int[n+1];
        dp[0] = 0; // 0잔일 때
        dp[1] = wine[1];
        dp[2] = wine[1] + wine[2];
        for(int i = 3; i < n+1; i++){
            // drinking
            dp[i] = max(dp[i-3]+wine[i-1]+wine[i],dp[i-2]+wine[i]);
            // not dirinking
            dp[i] = max(dp[i-1],dp[i]);
        }
        cout << dp[n];
    }
}

/* 
date: 0815
깨달은 점: 놓친 경우(x,x)가 있었다. 전체 경우를 다 고려했는지 다시 짚어보자. + 더 케이스 분류를 잘 했다면 쉽게 풀 수 있었을 것이다.
알고리즘: 다음 와인을 마시기 전에 나올 수 있는 경우의 수는 (x,x),(x,o),(o,x),(o,o)가 있다.
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int *wine = new int[n];
    for(int i = 0; i < n; i++){
        cin >> wine[i];
    }
    if(n == 1){
        cout << wine[0];
    } else if(n == 2){
        cout << wine[0]+wine[1];
    } else{
        int **dp = new int*[3];
        for(int i = 0; i < 3; i++){
            dp[i] = new int[n];
        }
        dp[0][0] = wine[0];
        dp[1][0] = wine[0];
        dp[2][0] = 0;
        
        dp[0][1] = wine[1];
        dp[1][1] = wine[0]+wine[1];
        dp[2][1] = wine[0];
        
        dp[0][2] = max(dp[0][0],dp[1][0]) + wine[2];
        dp[1][2] = dp[0][1] + wine[2];
        dp[2][2] = dp[1][1];
        if(n > 3){
            for(int i = 3; i < n; i++){
                dp[0][i] = max(dp[1][i-3], max(dp[0][i-2],dp[1][i-2])) + wine[i];
                dp[1][i] = dp[0][i-1] + wine[i];
                dp[2][i] = dp[1][i-1];
            }
        }
        cout << max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]));
    }

}
 */

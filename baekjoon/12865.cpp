/* 
[평범한 배낭]
- date: 24.07.15
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
#define weight first
#define value second
pair<int,int> input[100];
int dp[100003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K, answer = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> input[i].weight >> input[i].value;
    }
    for(int i = 0; i < N; i++){
        int w = input[i].weight;
        int v = input[i].value;
        for(int j = K; j >= w; j--){
            dp[j] = max(dp[j],dp[j-w] + v);
        }
    }
    for(int w = 0; w <= K; w++){
        answer = max(answer, dp[w]);
    }
    cout << answer;
    return 0;
}
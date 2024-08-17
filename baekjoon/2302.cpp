/* 
[극장 좌석]
- date: 24.08.16
- 분류: DP

- dp[i] : i 번째 좌석까지 고려했을 때, 가능한 가짓수
- dp[i] = dp[i-1] + dp[i-2]
- i가 vip좌석이면, dp[i]와 dp[i+1]은 모두 dp[i-1]로 유지.

- 초기값
dp[0] = 1 -> 실제로 0번 좌석은 없지만, dp[0]을 1으로 두면, 2번 좌석이 vip일 경우에도 한번에 처리해줄 수 있음.
dp[1] = 1 -> 1번좌석까지만 보면 무조건 경우의 수는 1
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, answer = 0, dp[41];
bool vip[41];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int vip_seat_no;
        cin >> vip_seat_no;
        vip[vip_seat_no] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        if(vip[i] || vip[i-1]) {
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];

    return 0;
}
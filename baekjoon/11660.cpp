/* 
[구간 합 구하기 5]
- date: 24.09.10
- 분류: DP, 누적 합

그냥 매번 합을 구해서 출력한다면,
O( (x2-x1)*(y2-y1)*M )로, 최악의 경우 1024 * 1024 * 100'000 정도로 10^11번의 연산이 필요하기 때문에, 제한시간인 1초안에 통과하기 힘들다.

- 정의: d[i][j]: (1,1) (i,j)로 이루어진 사각형의 합
- 점화식: dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j];
- 초기값: 
    dp[1][1] = (1,1)의 값
    dp[i][0] = 0
    dp[0][j] = 0

.....       ooooo     oo...     ooooo     oo...
..ooo   =   ooooo  -  oo...  -  .....  +  .....
..ooo       ooooo     oo...     .....     .....
 */
#include <bits/stdc++.h>
using namespace std;

int board[1025][1025];
long long dp[1025][1025];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int x1, y1, x2, y2;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]  + (long) board[i][j];
        }
    }
    while(M--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
    return 0;
}
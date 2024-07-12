/* 
[RGB거리]
- date: 24.07.11
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int d[1000][3];
int cost[1000][3];
enum Color{
    R,
    G,
    B
};
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cost[i][R] >> cost[i][G] >> cost[i][B];
    }
    d[0][R] = cost[0][R];
    d[0][G] = cost[0][G];
    d[0][B] = cost[0][B];
    for(int i = 1; i < N; i++){
        d[i][R] = min(d[i-1][G],d[i-1][B]) + cost[i][R];
        d[i][G] = min(d[i-1][R],d[i-1][B]) + cost[i][G];
        d[i][B] = min(d[i-1][R],d[i-1][G]) + cost[i][B];
    }
    cout << min(d[N-1][R],min(d[N-1][G],d[N-1][B]));
    return 0;
}
/*
d[i][j] = i번째 건물을 j색으로 칠하는 최소 비용
d[0][R] = cost[0][R]
d[i][R] = min(d[i-1][G],d[i-1][B]) + cost[i][R]
정답 => min(d[i][R], d[i][G], d[i][B])
*/
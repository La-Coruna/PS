/* 
[계단 오르기]
- date: 24.07.11
- 분류: dp
 */
#include <bits/stdc++.h>
using namespace std;
int d[303];
int stair[303];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stair[i];
    }
    if(n == 1){
        cout << stair[0];
        return 0;
    } else if (n == 2){
        cout << stair[0] + stair[1];
        return 0;
    }
    d[0] = stair[0];
    d[1] = stair[0] + stair[1];
    d[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for(int i = 3; i < n; i++){
        d[i] = max(d[i-2] + stair[i], d[i-3] + stair[i-1] + stair[i]);
    }
    cout << d[n-1];
    return 0;
}
/*
d = 최고 점수
d[0] = stair[0]
d[1] = stair[0] + stair[1]
d[2] = max(stair[0] + stair[2], stair[1] + stair[2])
d[3] = max(stair[0] + stair[1] + stair[3], stair[0] + stair[2] + stair[3])
     = max(d[1] + stair[3], stair[3-3] + stair[3-1] + stair[3])
d[n] = max(d[n-2] + stair[n], d[n-3] + stair[n-1] + stair[n])
*/
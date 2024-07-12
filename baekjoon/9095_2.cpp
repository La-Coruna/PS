/* 
[1, 2, 3 더하기]
- date: 24.07.11
- 분류: DP
 */
#include <bits/stdc++.h>

using namespace std;

int d[12];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,n;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 10; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    cin >> T;
    while(T--){
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}

/* 
1 = x       / x         / 0 (+ 1)   -> 0 + 0 + 1            d[1] = 1
2 = x       / 0 (+ 2)   / 1 (+ 1)   -> 0 + 1 + d[1]         d[2] = 2
3 = 0 (+ 3) / 1 (+ 2)   / 2 (+ 1)   -> 1 + d[1] + d[2]      d[3] = 1 + 1 + 2 = 4
4 = 1 (+ 3) / 2 (+ 2)   / 3 (+ 1)   -> d[1] + d[2] + d[3]
5 = 2 (+ 3) / 3 (+ 2)   / 4 (+ 1)   -> d[2] + d[3] + d[4]
 */
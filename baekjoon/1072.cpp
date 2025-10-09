/*
[게임] 
- date: 25.02.04
- 분류: math
- (Y+K)/(X+K) * 100 = Z + 1
*/
#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;
    long long z = y * 100 / x;

    // 승률 99%에서는 더 못올린다. 수식으로 증명 가능.
    if(z >= 99) {
        cout << -1;
        return 0;
    }

    long long p = x*z + x - 100 * y;
    long long q = 99 - z;
    long long a = p / q;
    if(a*q < p) a++;
    cout << a;

    return 0;
}
/* 
[곱셈]
- date: 24.06.26
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;

long long pow(long long A, long long B, long long C){
    if (B==1) return A % C;
    long long tmp = pow(A,B/2,C);
    tmp = (tmp * tmp) % C;
    if (B%2 == 0) return tmp;
    else return (tmp*A) % C;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A,B,C;
    cin >> A >> B >> C;
    cout << pow(A,B,C);
    return 0;
}

/* 
b = 2k or 2k+1

a^(2k) % c = ((a^k) % c)^2
a^(2k+1) % c = ((a^k) % c)^2 * (a % c)
 */
/* 
[소수 구하기]
- date: 24.08.18
- 분류: Math, Prime Number
 */
#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1'000'001, true);
void sieve(int n){
    isPrime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= n; j+=i){
            isPrime[j] = false;
        }
    } 
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;
    sieve(N);
    for(int i = M; i <= N; i++){
        if(isPrime[i]) cout << i << '\n';
    }

    return 0;
}
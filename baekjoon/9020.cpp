/* 
[골드바흐의 추측]
- date: 24.09.08
- 분류: Math, Prime Number
 */
#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(10'001, true);
void sieve(int n){
    isPrime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= n; j += i)
            isPrime[j] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;

    sieve(10'000);
    while(T--){
        cin >> n;
        for(int i = n/2; i >= 2 ; i--){
            if(isPrime[i] && isPrime[n-i]){
                cout << i << ' ' << n-i << '\n';
                break;
            }
        }
    }

    return 0;
}
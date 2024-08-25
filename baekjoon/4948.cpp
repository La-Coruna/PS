/* 
[베르트랑 공준]
- date: 24.08.25
- 분류: Math, Prime Number
 */
#include <bits/stdc++.h>
using namespace std;

#define Max_num 123456*2

bool isPrime[Max_num+1];

void sieve(){
    fill(isPrime+1, isPrime+1+Max_num, true);
    isPrime[1] = false;
    for(int i = 2; i*i <= Max_num; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= Max_num; j += i)
            isPrime[j] = false;
    }
}

int PrimeCnt(int n){
    int cnt = 0;
    for(int i = n+1; i <= 2*n; i++){
        if(isPrime[i]) cnt++;
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int N;
    while(true){
        cin >> N;
        if(N == 0) break; 
        cout << PrimeCnt(N) << '\n';
    }

    return 0;
}
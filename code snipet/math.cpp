#include <bits/stdc++.h>
using namespace std;

/* 
O(n^(1/2))
 */
bool isPrimeNum(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

/* 
[에라토스테네스의 체]
총 작업량 -> 소수 p마다 N/p만큼 작업해줌. (즉, 시그마 N/ P )
소수의 역수(1/p)의 합은 수학적으로 loglogN에 비례함.
따라서 시간복잡돋는 O(NlglgN)
 */
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

/* 
[소인수분해]
point 1) i*i <= n 까지만 반복
point 2) n을 n^(1/2)보다 작은 소수로 다 나누고도 n이 1이 아니면, n^(1/2)보다 큰 소수가 곱해져 있다는 것
 */
vector<int> PrimeFactorization(int n){
    vector<int> result;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            result.emplace_back(i);
        }
    }
    if(n != 1) result.emplace_back(n);
    return result;
}

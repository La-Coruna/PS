/*
[소인수분해]
- date: 24.08.18
- 분류: Math, Prime Number
 */
#include <bits/stdc++.h>
using namespace std;

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

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> result = PrimeFactorization(N);

    for(int prime : result){
        cout << prime << '\n';
    }

    return 0;
}
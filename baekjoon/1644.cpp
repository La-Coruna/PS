/*
[소수의 연속합] 
- date: 26.01.012
*/
#include <bits/stdc++.h>
using namespace std;

int N;
bool isPrimeNumber[4'000'001];
vector<int> primeNums;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 아리토스테네스의 체
    fill(isPrimeNumber+2, isPrimeNumber+N+1, true);
    for(int i = 2; i*i <= N; i++){
        if(!isPrimeNumber[i]) continue;
        for(int j = i*i; j <= N; j += i){
            isPrimeNumber[j] = false;
        }
    }
    for(int i = 2; i <= N; i++){
        if(!isPrimeNumber[i]) continue;
            primeNums.emplace_back(i);
    }

    int cur = 0, ans = 0;
    auto r = primeNums.begin(), l = primeNums.begin();
    for(; r != primeNums.end(); r++){
        cur += *r;
        while(cur > N && l != primeNums.end()){
            cur -= *l;
            l++;
        }
        if(cur == N) ans++;
    }

    cout << ans;

    return 0;
}
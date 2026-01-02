/*
[2026년이 기대되는 이유] 
- date: 26.01.02
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100'000;

vector<bool> isPrime(MAX_N+2);
void initIsPrime(int n){
    // isPrime 배열 초기화
    isPrime.assign(n+1, true);
    isPrime[1] = false;

    // 체로 거르기
    for(int i = 2; i*i <= n; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <=n; j+=i){
            isPrime[j] = false;
        }
    }
    return;
}

bool isSpecial(int N){
    if(!isPrime[N+1]) return false;
    
    /* 
    2026 (N=4, i=1~3)
    1) 2 026
    2) 20 26
    3) 202 6
    */
    string N_str = to_string(N);
    for(int i = 1; i < N_str.length(); i++){
        int l = stoi(N_str.substr(0,i));
        int r = stoi(N_str.substr(i));
        if(!isPrime[l*r+1]) return false;
    }

    return true;
}

vector<int> specialNumCnt(MAX_N+1,0);
void initSpecialNumCnt(){
    for(int i = 1; i <= MAX_N; i++){
        specialNumCnt[i] = specialNumCnt[i-1];
        if(isSpecial(i)) specialNumCnt[i]++;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;
    
    initIsPrime(MAX_N+2);
    initSpecialNumCnt();

    for(int i = 0; i < T; i++){
        cin >> N;
        cout << specialNumCnt[N] << '\n';
    }

    return 0;
}
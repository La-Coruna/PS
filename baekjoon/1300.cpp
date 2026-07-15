/*
[K번째 수] 
- date: 26.04.16
*/
#include <bits/stdc++.h>
using namespace std;

long long N, k;

// 각 행(i)마다 i*j가 x보다 작거나 같은 수의 개수를 구해서 총 합을 구할 것임.
// -> 각 행마다 x보다 작거나 같은 수의 개수 : min(floor(x / i), N)
// 총 합이 k보다 작으면 false, 같거나 크면 true
bool func(long long x){
    long long cnt = 0;
    for(long long i = 1; i <= N; i++){
        cnt += min(x/i, N);
    }
    return cnt >= k;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k;

    long long s = 1, e = N*N;

    while(s < e){
        long long mid = (s + e) / 2;
        if(func(mid)){
            e = mid;
        } else{
            s = mid + 1;
        }
    }

    cout << e;

    return 0;
}
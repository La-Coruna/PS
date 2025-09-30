/*
[동전 2] 
- date: 25.09.30
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, coin[100];
int minCnt[10'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    
    sort(coin, coin+n, greater<int>());

    fill(minCnt + 1, minCnt + k + 1, -1); // minCnt[0] = 0

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(minCnt[j] == -1) continue; // 만들 수 있는 가지수가 아니면 패스

            int nv = j + coin[i];
            if(nv > k) continue; // 조건 k를 넘으면 패스

            int nv_cnt = minCnt[j] + 1;
            if(minCnt[nv] == -1 || nv_cnt < minCnt[nv]) minCnt[nv] = nv_cnt; // 더 적은 동전으로 만들 수 있다면 갱신
        }
    }
    
    cout << minCnt[k];

    return 0;
}
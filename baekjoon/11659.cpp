/* 
[구간 합 구하기 4]
- date: 24.07.12
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int d[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d[0]=0;
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        d[i] = d[i-1] + arr[i];
    }
    while(M--){
        //합 구하기
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << '\n';
    }
    return 0;
}
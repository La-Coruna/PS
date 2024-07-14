/* 
[동전 0]
- date: 24.07.12
- 분류: Greedy
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K, arr[10];
    int answer = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = N-1; i >= 0; i--){
        answer += K/arr[i];
        K %= arr[i];
    }
    cout << answer;
    return 0;
}
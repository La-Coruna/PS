/* 
[수 고르기]
- date: 24.07.24
- 분류: Two Pointers
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, arr[100000], answer = 2000000001;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int st = 0, en = 0;
    while(true){
        if(st >= N || en >= N) break;
        int cur = arr[en] - arr[st];
        if(cur >= M){
            answer = min(answer, cur);
            st++;
            continue;
        }
        else {
            en++; continue;
        }

    }
    cout << answer;
    return 0;
}
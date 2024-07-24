/* 
[수 고르기]
- date: 24.07.24
- 분류: Binary Search
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
    for(int i = 0; i < N; i++){
        int st = arr[i];
        int* en = lower_bound(arr,arr+N,st+M);
        if(en >= arr+N) continue;
        answer = min(answer,(*en - st));
    }
    cout << answer;
    return 0;
}
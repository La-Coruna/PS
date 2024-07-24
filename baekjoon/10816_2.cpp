/* 
[숫자 카드 2]
- date: 24.07.24
- 분류: Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, target, arr[500000] = {0};
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> M;
    sort(arr, arr+N);
    for(int i = 0; i < M; i++){
        cin >> target;
        int st = lower_bound(arr, arr+N, target) - arr;
        int en = upper_bound(arr, arr+N, target) - arr;
        cout << en - st << ' ';
    }
    
    return 0;
}
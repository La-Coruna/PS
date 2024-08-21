/* 
[좌표 압축]
- date: 24.08.21
- 분류: Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
    int N, arr[1'000'000], sorted_arr[1'000'000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }
    sort(sorted_arr, sorted_arr+N);

    int end_idx = unique(sorted_arr, sorted_arr+N) - sorted_arr;

    for(int i = 0; i < N; i++){
        cout << lower_bound(sorted_arr, sorted_arr+end_idx, arr[i]) - sorted_arr << ' ';
    }

    return 0;
}
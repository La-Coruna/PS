/* 
[N과 M (12)]
- date: 24.08.12
- 분류: Backtracking
 */

#include <bits/stdc++.h>
using namespace std;

int N, M, arr[8], output[8];

void func(int k){
    if(k == M) {
        for(int i = 0; i < M; i++) cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    int last = -1;
    for(int i = 0; i < N; i++){
        if(last == arr[i] || (k > 0 && arr[i] < output[k-1])) continue;
        output[k] = arr[i];
        func(k+1);
        last = arr[i];
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    func(0);

    return 0;
}
/* 
[N과 M (5)]
- date: 24.07.26
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[8], output[8], issued[8];

void func(int k){
    if(k == M) {
        for(int i = 0; i < M; i++) cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(issued[i]) continue;
        issued[i] = true;
        output[k] = arr[i];
        func(k+1);
        issued[i] = false;
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
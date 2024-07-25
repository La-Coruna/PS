/* 
[N과 M (3)]
- date: 24.07.25
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[7];

void func(int k){
    if(k == M) {
        for(int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        arr[k] = i+1;
        func(k + 1);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);

    return 0;
}
/* 
[N과 M (4)]
- date: 24.07.25
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[8];

void func(int k){
    if(k==M){
        for(int i = 0; i < M; i++){cout << arr[i] << ' ';}
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(k > 0 && i < arr[k-1] ) continue;
        arr[k] = i;
        func(k+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);

    return 0;
}
/* 
[N과 M (2)]
- date: 24.07.25
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, arr[8];
bool issued[8];

void func(int k){
    if(k == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){ // i+1이 실제 들어가는 값
        if(issued[i]) continue;
        if(k >= 1 && i+1 < arr[k-1]) continue;
        issued[i] = true;
        arr[k] = i+1;
        func(k+1);
        issued[i] = false;
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
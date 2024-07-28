/* 
[N과 M (7)]
- date: 24.07.28
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, input[7], output[7];
void func(int k){
    if(k == M) {
        for(int i = 0; i < M; i++) cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        output[k] = input[i];
        func(k+1);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> input[i];
    sort(input, input + N);
    func(0);
    return 0;
}
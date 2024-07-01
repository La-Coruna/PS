/* 
[N과 M (1)]
- date: 24.06.29
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
bool issued[10];

void func(int k){
    if(k == M){
        for(int i = 0; i < k; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(issued[i]) continue;
        arr[k] = i;
        issued[i] = true;
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
/* 
[바구니 뒤집기]
- date: 24.07.20
- 분류: super easy
 */
#include <bits/stdc++.h>
using namespace std;
int arr[102];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        arr[i] = i;
    }
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        reverse(arr+a,arr+b+1);
    }
    for(int i = 1; i <= N; i++)
        cout << arr[i] << ' ';

    return 0;
}
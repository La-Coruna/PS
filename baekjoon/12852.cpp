/* 
[1로 만들기 2]
- date: 24.07.12
- 분류: DP
 */
#include <bits/stdc++.h>
using namespace std;
int d[1000001];
int pre[1000001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int X;
    cin >> X;
    d[1] = 0;
    d[2] = 1;
    pre[2] = 1;
    d[3] = 1;
    pre[3] = 1;
    for(int i = 4; i <= X; i++){
        d[i] = d[i-1];
        pre[i] = i-1;
        if(i%2 == 0 && d[i] > d[i/2]){
            d[i] = d[i/2];
            pre[i] = i/2;
        }
        if(i%3 == 0 && d[i] > d[i/3]){
            d[i] = d[i/3];
            pre[i] = i/3;
        }
        d[i]++;
    }
    cout << d[X] << '\n';
    for(int i = X; i != 1; i = pre[i]){
        cout << i << ' ';
    }
    cout << 1;
    return 0;
}
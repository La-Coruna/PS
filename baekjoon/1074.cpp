/* 
[Z]
- date: 24.06.27
- 분류: recursion
 */
#include <bits/stdc++.h>
using namespace std;
int func(int N,int r,int c){
    if(N == 1){
        if(r==0){
            if(c==0) return 0;
            else return 1;
        } else{
            if(c==0) return 2;
            else return 3;
        }
    }
    int half = (1 << N) / 2;
    if(r < half){
        //왼위
        if(c < half) return func(N-1,r,c);
        //오위
        else return func(N-1,r,c-half) + half*half;
    } else{
        //왼밑
        if(c < half) return func(N-1,r-half,c) + 2*half*half;
        //오밑
        else return func(N-1,r-half,c-half) + 3*half*half;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N,r,c);
    return 0;
}
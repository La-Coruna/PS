/* 
[보물]
- date: 24.07.14
- 분류: Greedy
 */
#include <bits/stdc++.h>
using namespace std;
int A[53];
int B[53];
int answer;
int main (void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A,A+N);
    sort(B,B+N,[](int a, int b){return a>b;});
    for(int i = 0; i < N; i++){
        answer += A[i]*B[i];
    }
    cout << answer;
    return 0;
}
/* 
[소수 찾기]
- date: 24.08.18
- 분류: Math, Prime Number
 */
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, input, answer = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(isPrime(input)) answer++;
    }
    cout << answer;

    return 0;
}
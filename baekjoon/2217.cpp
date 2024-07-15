/* 
[로프]
- date: 24.07.14
- 분류: Greedy
 */
#include <bits/stdc++.h>
using namespace std;
int input[100003];
int main (void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, answer;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    sort(input, input+N, [](int a, int b){return a > b;});
    answer = input[0];
    for(int i = 1; i<N; i++){
        int tmp = input[i] * (i+1);
        if(answer < tmp) answer = tmp;
    }
    cout << answer;
    return 0;
}
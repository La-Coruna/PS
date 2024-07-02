/* 
[부분수열의 합]
- date: 24.07.02
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, S;
int answer = 0;
int input[20];

void func(int k, int sum){
    if(k == N){
        if(sum == S) answer++;
        return;
    }
    func(k+1, sum + input[k]);
    func(k+1, sum);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> input[i];
    func(0, 0);
    if(S == 0) answer--;
    cout << answer;
    return 0;
}
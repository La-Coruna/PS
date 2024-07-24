/* 
[부분합]
- date: 24.07.24
- 분류: Two Pointers
*/
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, S, arr[100000], answer = 100003;
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int st = 0, en = 0;
    int sum = arr[0];
    while(true){
        if(sum < S){
            if(++en >= N) break;
            sum += arr[en];
        } else {
            answer = min(en - st + 1, answer);
            sum -= arr[st];
            if(++st >= N) break;
        } 
    }
    if(answer == 100003) cout << 0;
    else cout << answer;

    return 0;
}
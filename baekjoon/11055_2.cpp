/*
[가장 큰 증가하는 부분 수열]
- date: 24.07.28
- 분류: DP
- d[i]: i번째 수열을 넣었을 때의 최대 값.
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000];
int d[1000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    d[0] = arr[0];
    for(int i = 1; i < N; i++){
        d[i] = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[j] >= arr[i]) continue;
            d[i] = max(d[i], d[j] + arr[i]);
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        answer = max(d[i], answer);
    }
    
    cout << answer;

    return 0;
}
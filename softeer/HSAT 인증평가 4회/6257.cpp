/*
[통근버스 출발 순서 검증하기] 
- date: 24.11.08
- url: https://softeer.ai/practice/6257
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[5000]; // 3 <= N <= 5'000
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    long long ans = 0;
    for(int i = 0; i < N; i++){
        int biggerThanI = 0;
        for(int j = i+1; j < N; j++){
            if(arr[j] > arr[i]) biggerThanI++;
            else ans += (long long)biggerThanI; // arr[j] < arr[i]의 경우
        }
    }

    cout << ans;

    return 0;
}
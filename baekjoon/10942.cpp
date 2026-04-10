/*
[팰린드롬?] 
- date: 26.04.10
*/
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[2001], dist_from_mid_odd[2001], dist_from_mid_even[2001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    // 전체 팰린드롬 계산
    for(int i = 1; i <= N; i++){
        // 홀수
        int j = i-1;
        for(; (j >= 1) && (2*i - j <= N); j--){
            if(arr[j] != arr[2*i - j]) break;
        }
        dist_from_mid_odd[i] = i - (j+1);

        // 짝수
        j = i;
        for(; (j >= 1) && (2*i - j + 1 <= N); j--){
            if(arr[j] != arr[2*i - j + 1]) break;
        }
        dist_from_mid_even[i] = i - j;
    }

    cin >> M;

    // 질문 대답
    for(int i = 0; i < M; i++){
        int S, E, mid, dist;
        cin >> S >> E;
        mid = (S+E)/2;
        bool isEven = (S+E) & 1; // 질문 범위가 짝수인지
        dist = E - mid; // even도 되도록 mid - S 대신 E - mid 사용

        if(isEven){
            if(dist <= dist_from_mid_even[mid]) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else{
            if(dist <= dist_from_mid_odd[mid]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    
    return 0;
}
/* 
[21년 재직자 대회 예선] 비밀 메뉴
- date: 24.09.05
- tag: pattern matching
- url: https://softeer.ai/practice/6269
- g++기준에서 strstr 함수는 선형 시간에 동작하기 때문에,
- 패턴의 등장 여부만 확인한다면 strstr로 날먹 가능.
- 그렇지 않다면 KMP
 */

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    char secret_menu[101];
    char user_input[101];
    
    cin >> M >> N >> K;
    for(int i = 0; i < M; i++) cin >> secret_menu[i];
    secret_menu[M] = 0;
    for(int i = 0; i < N; i++) cin >> user_input[i];
    user_input[N] = 0;

    char* found = strstr(user_input, secret_menu);

    if(found) cout << "secret";
    else cout << "normal";

    return 0;
}
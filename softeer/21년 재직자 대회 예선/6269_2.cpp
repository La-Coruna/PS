/* 
[21년 재직자 대회 예선] 비밀 메뉴
- date: 24.12.28
- tag: string, pattern matching
- url: https://softeer.ai/practice/6269
- string의 find를 써보았다. 매칭된 문자열이 없으면 string::npos를 반환한다.
 */

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string secretCode, order, input;
    int M, N, K;
    cin >> M >> N >> K;
    for(int  i = 0; i < M; i++){
        cin >> input;
        secretCode += input;
    }

    for(int  i = 0; i < N; i++){
        cin >> input;
        order += input;
    }

    if(order.find(secretCode) == string::npos)
        cout << "normal";
    else
        cout << "secret";
    
    return 0;
}
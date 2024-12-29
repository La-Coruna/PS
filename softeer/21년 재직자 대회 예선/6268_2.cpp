/*
[21년 재직자 대회 예선] 전광판
- date: 24.12.29
- tag: simulation    
- url: https://softeer.ai/practice/6268
*/
#include <bits/stdc++.h>
using namespace std;

bool digit[11][7] = {
    /*
     0
    1 2
     3
    4 5
     6
    */

    // 0
    {1,
    1,1,
     0,
    1,1,
     1},
    
    // 1
    {0,
    0,1,
     0,
    0,1,
     0},
    
    // 2
    {1,
    0,1,
     1,
    1,0,
     1},
    
    // 3
    {1,
    0,1,
     1,
    0,1,
     1},
    
    // 4
    {0,
    1,1,
     1,
    0,1,
     0},
    
    // 5
    {1,
    1,0,
     1,
    0,1,
     1},
    
    // 6
    {1,
    1,0,
     1,
    1,1,
     1},
    
    // 7
    {1,
    1,1,
     0,
    0,1,
     0},
    
    // 8
    {1,
    1,1,
     1,
    1,1,
     1},
    
    // 9
    {1,
    1,1,
     1,
    0,1,
     1},

    // x
    {0,
    0,0,
     0,
    0,0,
     0},
};

int compare1Digit(int a, int b){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(digit[a][i] != digit[b][i]) cnt++;
    }
    return cnt;
}

int compareAllDigit(int A, int B){
    int cnt = 0, a, b;
    for(int i = 0; i < 5; i++){
        // A
        if(A != 0){
            a = A % 10;
            A /= 10;
        } else
            a = 10;
        // B
        if(B != 0){
            b = B % 10;
            B /= 10;
        } else
            b = 10;
        // compare
        cnt += compare1Digit(a,b);
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, A, B;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << compareAllDigit(A,B) << '\n';
    }

    return 0;
}
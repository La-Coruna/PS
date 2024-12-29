/*
[21년 재직자 대회 예선] 전광판
- date: 24.09.10
- tag: simulation    
- url: https://softeer.ai/practice/6268
    0
1        2
    3
4        5
    6
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> digit[11];

void Init(){
    //         {0, 1, 2, 3, 4, 5, 6};
    digit[0] = {1, 1, 1, 0, 1, 1, 1};
    digit[1] = {0, 0, 1, 0, 0, 1, 0};
    digit[2] = {1, 0, 1, 1, 1, 0, 1};
    digit[3] = {1, 0, 1, 1, 0, 1, 1};
    digit[4] = {0, 1, 1, 1, 0, 1, 0};
    digit[5] = {1, 1, 0, 1, 0, 1, 1};
    digit[6] = {1, 1, 0, 1, 1, 1, 1};
    digit[7] = {1, 1, 1, 0, 0, 1, 0};
    digit[8] = {1, 1, 1, 1, 1, 1, 1};
    digit[9] = {1, 1, 1, 1, 0, 1, 1};
    digit[10] = {0, 0, 0, 0, 0, 0, 0};
}

int compare_1digit(int a, int b){
    int diff_cnt = 0;
    for(int i = 0; i < 7; i++){
        if(digit[a][i] != digit[b][i]) diff_cnt++;
    }
    return diff_cnt;
}

int compare_digit(int a, int b){
    int diff_cnt = 0;
    for(int i = 1; i < 100000; i*=10){
        int _a = 10, _b = 10;
        if(a >= i) 
            _a = (a / i) % 10;
        if(b >= i)
            _b = (b / i) % 10;
        diff_cnt += compare_1digit(_a,_b);
    }
    return diff_cnt;
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Init();

    int T, A, B;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << compare_digit(A,B) << '\n';
    }

    return 0;
}
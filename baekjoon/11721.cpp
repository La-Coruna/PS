/* 
[열 개씩 끊어 출력하기]
- date: 0909
- 분류: 입출력 연습, 문자열
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    int s = N.size();

    for(int i = 0; i < s /10; i++){
        for(int j = 0; j < 10; j++){
            cout << N[i*10+j];
        }
        cout << "\n";
    }
    for(int j = 0; j < s%10; j++){
        cout << N[(s/10)*10 + j];
    }

    return 0;
}

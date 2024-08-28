/* 
[별 찍기 - 10]
- date: 24.08.28
- 분류: Recursion

- 이전 문자열을 사용해서 다음 문자열을 만들려고 하면 안된다. -> 더 복잡하게 생각하는 꼴
- 좌표로 생각해서 거기에는 무슨 값인지 찾는 방법이 훨씬 쉽다.
 */
#include <bits/stdc++.h>
using namespace std;

char func(int n, int x, int y){
    if(n==1) return '*';

    x%= n;
    y%= n;

    //가운데면 구멍 뚫기
    if(x >= n/3 && x <= 2*n/3-1 && y >= n/3 && y <= 2*n/3-1) return ' ';
    else return func(n/3, x, y);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << func(N,i,j);
        }
        cout << "\n";
    }

    return 0;
}
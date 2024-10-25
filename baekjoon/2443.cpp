/*
[별 찍기 - 6] 
- date: 24.10.24
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++)
            cout << ' ';
        for(int j = 0; j < 2*(N-i)-1; j++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}
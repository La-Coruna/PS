/*
[과자 나눠주기] 
- date: 24.10.25
- 분류: binary search, parametric search
- 최적화 문제: 과자 M개를 만들 수 있는 최대 과자의 길이
- 결정 문제: 과자의 길이가 X일 때 과자를 M개 이상 만들 수 있는가.
*/
#include <bits/stdc++.h>
using namespace std;

int M, N; // M:조카 수 N:과자 수
int cookie[1'000'000];

bool solve(int x){
    if(x == 0) return true;
    long long res = 0;
    for(int i = 0; i < N; i++){
        res += cookie[i] / x;
    }
    return res >= M;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        cin >> cookie[i];
    }
    sort(cookie, cookie+N);

    int st = 0, en = *max_element(cookie, cookie+N);
    while(st < en){
        int mid = (st + en + 1)/2;
        bool canDo = solve(mid);
        if(canDo) st = mid;
        else en = mid - 1;
    }
    cout << st;

    return 0;
}
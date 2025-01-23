/*
[공유기 설치] 
- date: 25.01.16
- 분류: parametric search
*/
#include <bits/stdc++.h>
using namespace std;

int N, C;
int x[200'001];

bool solve(int minDist){
    int cnt = 1; // 맨 처음 집에 하나 설치
    int prev = 0;
    int cur = 1;
    while(cur < N){
        if(x[cur] - x[prev] >= minDist){
            if(++cnt == C)
                return true;
            prev = cur++;
        } else
            cur++;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }

    int st = 1;
    int en = x[N-1] - x[0];
    sort(x, x+N);
    while(st < en){
        int mid = (st + en+1)/2;
        if(solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;

    return 0;
}
/* 
[랜선 자르기]
- date: 24.08.23
- 분류: Binary Search, Parametric Search

- K개인 랜선을 길이 X로 잘랐을 때 N개로 만들 수 있나? X의 최대값은?
- 1 <= X <= 2^31-1
- X가 충분히 작으면 N개를 만들 수 있음.
 */
#include <bits/stdc++.h>
using namespace std;

int K, N, arr[10'000];

bool solve(int X){
    int cnt = 0;
    for(int i = 0; i < K; i++){
        cnt += arr[i] / X;
    }
    return cnt >= N;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> arr[i];
    }
    int st = 1, en = 0x7fffffff;

    int last = 0;
    while(st < en){
        int mid = st + (en - st + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;

    return 0;
}
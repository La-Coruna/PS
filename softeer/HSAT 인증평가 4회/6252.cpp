/*
[슈퍼컴퓨터 클러스터] 
- date: 24.11.07
- url: https://softeer.ai/practice/6252
*/
#include <bits/stdc++.h>
using namespace std;

int N;
long long B, arr[100'000];


bool solve(long long X){
    long long total_cost = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] >= X || B < total_cost ) break;
        long long cur_cost = (X - arr[i]);
        total_cost += cur_cost * cur_cost;
    }
    return B >= total_cost;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);

    long long st = arr[0], en = 2'000'000'000;
    while(st < en){
        long long mid = (st + en + 1)/2;
        //cout << mid << " -> ";
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;

    return 0;
}
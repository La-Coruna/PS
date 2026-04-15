/*
[용돈 관리] 
- date: 26.04.15
- 분류: parametric search

- s와 e 잘 설정해주기
- s = x의 최소 값 -> max(arr)값으로 매일 인출하는 상황
- e = 한번 인출해서 N일 동안 사용하는 상황 -> arr[i]의 합 <= 10'000(하루 최대 생활비) * 100'000(N의 최대값) = 1'000'000'000 = 1e9

1 ≤ N ≤ 100,000

*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100'000];

// x는 arr[i]의 최대값보다 작지 않다는 전제
bool func(int x){
    int cnt = 1, money = x;
    for(int i = 0; i < N; i++){
        if(money < arr[i]) {
            money = x;
            cnt++;
        }
        money -= arr[i];
    }
    return cnt <= M;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    // M번 이하 인출로 생존 가능한, 최소 금액 X 찾기
    // false | true
    int s = *max_element(arr, arr+N), e = 1e9;
    while(s<e){
        int mid = (s + e) / 2;
        if(func(mid)){
            e = mid;
        } else {
            s = mid+1;
        }
    }

    cout << e;

    return 0;
}
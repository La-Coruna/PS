/* 
[연산자 끼워넣기]
- date: 24.09.05
- 분류: Backtracking
- N이 11이하이기 때문에, 4^11을 해도 4'194'304 정도이다.
 */
#include <bits/stdc++.h>
using namespace std;

int N, arr[11], oper[4], res;
int max_value = 0x80000000;
int min_value = 0x7fffffff;


void func(int k){
    if(k == N){
        if(res > max_value) max_value = res;
        if(res < min_value) min_value = res;
        return;
    }

    int tmp = res;
    if(oper[0] > 0){
        res += arr[k];
        oper[0]--;
        func(k+1);
        res = tmp;
        oper[0]++;
    }
    if(oper[1] > 0){
        res -= arr[k];
        oper[1]--;
        func(k+1);
        res = tmp;
        oper[1]++;
    }
    if(oper[2] > 0){
        res *= arr[k];
        oper[2]--;
        func(k+1);
        res = tmp;
        oper[2]++;
    }
    if(oper[3] > 0){
        res /= arr[k];
        oper[3]--;
        func(k+1);
        res = tmp;
        oper[3]++;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++) cin >> oper[i];

    res = arr[0];
    func(1);

    cout << max_value << '\n' << min_value;

    return 0;
}
/*
[용액] 
- date: 26.01.20
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[100'000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    // 이미 오름차순으로 입력됨.
    // sort(arr,arr+N);

    int x, y;
    int cur_abs_sum = 0x7f7f7f7f;
    for(int i = 0; i < N-1; i++){
        int target_value = -arr[i];
        auto idx = lower_bound(arr+i+1, arr+N, target_value);
        
        // 오른쪽 값
        if(idx < arr+N){
            int r = *idx;
            int new_abs_sum = abs(arr[i] + r);
            if(new_abs_sum < cur_abs_sum){
                x = arr[i];
                y = r;
                cur_abs_sum = new_abs_sum;
            }
        }

        // 왼쪽 값
        if(idx-1 > arr+i){
            int l = *(idx-1);
            int new_abs_sum = abs(arr[i] + l);
            if(abs(arr[i] + l) < cur_abs_sum){
                x = arr[i];
                y = l;
                cur_abs_sum = new_abs_sum;
            }
        }
    }

    cout << x << ' ' << y;

    return 0;
}
/* 
[세 수의 합]
- date: 24.08.22
- 분류: Binary Search
 */
/* 
생각
2) 1000개의 숫자 중에서 3개를 뽑는 경우 -> 1000C3 = 약 1000^3 / 6 = 10^9 / 6 -> O(n^3)
3) 3개의 합이 arr에 있는지 판단 -> O(lgN)
예상 시간 복잡도: O((n^3)lgn)
-> 이건 안된다. O((n^2)lgn)으로 푸는 테크닉 사용해야함.
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[1000];
    vector<int> two;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            two.push_back(arr[i] + arr[j]);
        }
    }
    sort(two.begin(), two.end());
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(two.begin(), two.end(), arr[i] - arr[j])){
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}
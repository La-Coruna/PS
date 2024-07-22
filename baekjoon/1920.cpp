/* 
[수 찾기]
- date: 24.07.22
- 분류: Binary Search
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, arr[100000], target;

bool BinarySearch(int target){
    int st = 0, en = N-1;
    while(st <= en){
        int mid = (st + en) / 2;
        if(target < arr[mid]) {
            en = mid - 1;
        }
        else if(target > arr[mid]) {
            st = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> target;
        //cout << BinarySearch(target) << '\n';
        cout << binary_search(arr, arr+N, target) << '\n';
    }

    return 0;
}
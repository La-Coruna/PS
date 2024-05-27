#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int nums[105];
    int v;
    int cnt = 0;

    // 1. input N
    cin >> N;

    // 2. input numbers
    for (int i = 0; i<N; i++){
        cin >> nums[i];
    }

    // 3. input v
    cin >> v;

    // 4. v가 몇 개 있는지 카운팅
    for (int i = 0; i<N; i++){
        if(nums[i] == v)
            cnt++;
    }

    cout << cnt;

    return 0;
}
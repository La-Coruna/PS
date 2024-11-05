/*
[자동차 테스트] 
- date: 24.10.28
- url: https://softeer.ai/practice/6247
*/
#include <bits/stdc++.h>
using namespace std;

int arr[50'000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    // for(auto c: arr)
    //     cout << c << ' ';
    // cout << "\n";

    while(q--){
        int c;
        cin >> c;
        auto idx = lower_bound(arr.begin(), arr.end(), c);
        if(idx == arr.end() || c != *idx) {
            cout << "0\n";
            continue;
        }
        int l = idx - arr.begin();
        int r = arr.end() - idx - 1;
        // cout << "c: " << c << ", " << l << " " << r << " -> ";
        cout << l * r <<'\n';
    }


    return 0;
}
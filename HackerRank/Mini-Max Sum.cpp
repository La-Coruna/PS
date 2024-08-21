/* 
[Mini-Max Sum]
- date: 24.08.21
- tag: easy
 */
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    long long min = 0, max = 0;
    int sz = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < 4; i++){
        min += arr[i];
    }
    for(int i = 0; i < 4; i++){
        max += arr[sz-1-i];
    }
    cout << min << ' ' << max;
}
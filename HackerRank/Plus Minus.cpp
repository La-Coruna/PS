/* 
[Plus Minus]
- date: 24.08.21
- tag: easy
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    float pos_cnt = 0, neg_cnt = 0, zero_cnt = 0;
    for(int a: arr){
        if(a>0) pos_cnt++;
        else if(a<0) neg_cnt++;
        else zero_cnt++;
    }
    int sz = arr.size();
    cout << pos_cnt / sz << '\n' << neg_cnt / sz << '\n' << zero_cnt / sz;
}
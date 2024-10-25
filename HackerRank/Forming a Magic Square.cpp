/*
[Forming a Magic Square] 
- date: 24.10.25
- tag: simulation, magic square
- url: https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true
*/
#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

vector<vector<int>> ans[8] = {  
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, // 
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}, // 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}, // 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, // 
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
};

int compareMatrix(vector<vector<int>> &s, vector<vector<int>> &t){
    int res = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            res += abs(s[i][j] - t[i][j]);
        }
    }
    return res;
}

int formingMagicSquare(vector<vector<int>> s) {
    int minRes = 100;
    for(int i = 0; i < 8; i++){
        minRes = min(minRes,compareMatrix(s, ans[i]));
    }
    return minRes;
}
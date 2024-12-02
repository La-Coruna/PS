/*
[하노이의 탑]
- date: 24.12.02
- url: https://school.programmers.co.kr/learn/courses/30/lessons/12946

1 : [1,3]
2 : [1,2][1,3][2,3]
3 : [1,3][1,2][3,2] [1,3] [2,1][2,3][1,3]
4 : [1,2][1,3][2,3][1,2][3,1][2,1][1,2][1,3](+2번째 기둥에 있는 3개의 탑을 3번째로 옮기기.)

f(n,a,b) : n개의 원판을 a에서 b로 옮기기
1 : f(1,1,3)
2 : f(2,1,3) = f(1,1,2) f(1,1,3) f(1,2,3)
    f(2,1,2) = f(1,1,3) f(1,1,2) f(1,3,2)
    f(2,2,3) = f(1,2,1) f(1,2,3) f(1,1,3)
    
3 : f(3,1,3) = f(2,1,2) f(1,1,3) f(2,2,3)
4 : f(4,1,3) = f(3,1,2) f(1,1,3) f(3,2,3)

n : f(n,a,b) = f(n-1,a,c) f(1,a,b) f(n-1,c,b)
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> f(int n, int a, int b){
    if(n == 1) return {{a,b}};
    int c = 6 - a - b;
    vector<vector<int>> res = f(n-1,a,c);
    res.push_back({a,b});
    vector<vector<int>> post = f(n-1,c,b);
    res.insert(res.end(), post.begin(), post.end());
    return res;
}

vector<vector<int>> solution(int n) {
    return f(n,1,3);
}
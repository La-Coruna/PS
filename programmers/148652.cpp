/*
[유사 칸토어 비트열]
- date: 24.11.30
- url: https://school.programmers.co.kr/learn/courses/30/lessons/135808
*/

#include <bits/stdc++.h>

using namespace std;

// 0(1) : 1                                 1
// 1(5) : 11011                             4
// 2(25) : 11011 11011 00000 11011 11011    16

// 3(125): 11011 11011 00000 11011 11011    64
//       : 11011 11011 00000 11011 11011
//       : 11011 11011 00000 11011 11011
//       : 11011 11011 00000 11011 11011
//       : 11011 11011 00000 11011 11011

int func(int n, long long k){
    if(n == 0) return 1;
    int res = 0;
    long long line1 = pow(5,n-1);
    int q = (int) (k / line1);
    long long r = k % line1;
    for(int i = 0; i < q; i++){
        if(i == 2 ) continue;
        res += pow(4,n-1);
        //cout << res << '\n';
    }
    if(r != 0 && q != 2) res += func(n-1, r);
    //if(r != 0) res += func(n-1, r);
    return res;
}

int solution(int n, long long l, long long r) {
    int answer = func(n, r) - func(n,l-1);
    return answer;
}
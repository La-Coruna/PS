/*
[과일 장수]
- date: 24.11.30
- url: https://school.programmers.co.kr/learn/courses/30/lessons/135808
*/

#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    int lenScore = score.size();
    for(int i = m - 1; i < lenScore ; i += m){
        answer += score[i]*m;
    }
    
    return answer;
}
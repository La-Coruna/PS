/*
[혼자 놀기의 달인]
- date: 24.12.01
- url: https://school.programmers.co.kr/learn/courses/30/lessons/131130

1 2 3 4 5 6 7 8
8 6 3 7 2 5 1 4
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    vector<int> scores;
    vector<bool> vis(cards.size(), false);
    for(int box_num = 1; box_num <= cards.size(); box_num++){
        if(vis[box_num-1]) continue;
        int cur_score = 0;
        int cur_card = cards[box_num-1];
        vis[box_num-1] = true;
        while(true){
            cur_score ++;
            if(vis[cur_card-1]) break;
            vis[cur_card-1] = true;
            cur_card = cards[cur_card - 1];
        }
        scores.emplace_back(cur_score);
    }
    sort(scores.begin(),scores.end(), greater<int>());
    
    if(scores.size() == 1) return 0;
    else return scores[0]*scores[1];
}
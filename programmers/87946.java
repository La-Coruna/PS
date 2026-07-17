/*
[피로도]
- date: 2026-07-16
- url: https://school.programmers.co.kr/learn/courses/30/lessons/87946
*/

import java.util.*;

class Solution {
    public int func(int cur_k, int cur_trial, int[][] dungeons, boolean[] vis){
        int max_cnt = cur_trial;
        for(int i = 0; i < dungeons.length; i++){
            if(cur_k < dungeons[i][0] || vis[i]) continue;
            vis[i] = true;
            max_cnt = Math.max(max_cnt,func(cur_k-dungeons[i][1], cur_trial+1, dungeons, vis));
            vis[i] = false;
        }
        return max_cnt;
    }
    
    public int solution(int k, int[][] dungeons) {
        return func(k, 0, dungeons, new boolean[dungeons.length]);
    }
}

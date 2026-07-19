/*
[더 맵게]
- date: 2026-07-18
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42626
*/

import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int s: scoville){
            pq.offer(s);
        }
        
        while(!pq.isEmpty()){
            int u, v;
            u = pq.poll();
            if(u >= K) break;
            
            // 합쳐야 하는데 다음 께 없음.
            if(pq.isEmpty()){
                return -1;
            }
            
            v = pq.poll();
            pq.offer(u + v*2);
            answer++;
        }
        return answer;
    }
}

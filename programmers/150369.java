/*
[택배 배달과 수거하기]
- date: 2026-07-26
- url: https://school.programmers.co.kr/learn/courses/30/lessons/150369
*/

/*
가장 멀리 있는 곳부터 배달과 수거를 완수해가면 되지 않을까? 그리디 방식으로.

수거는 어차피 물류창고로 오는 길에만 하고
배달은 가는 길에 만하니까,

출발할 때 가장 많이 챙기고,
돌아올 때도 가장 많이 수거할 수 있는 만큼 수거

구현은 집을 역순으로 차례차례 배달 및 수거하기.
*/
import java.util.*;
class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        int last_d_idx = n-1;
        int last_p_idx = n-1;
        long total_dist = 0;
        
        while(last_d_idx >= 0 || last_p_idx >= 0){
            // 제일 먼 도착 지점 갱신
            while(last_d_idx >= 0 && deliveries[last_d_idx] == 0) last_d_idx--;
            while(last_p_idx >= 0 && pickups[last_p_idx] == 0) last_p_idx--;
            
            if(last_d_idx < 0 && last_p_idx < 0) break;
            
            // 이동거리 추가
            total_dist += (Math.max(last_d_idx,last_p_idx)+1) * 2;
            
            // 실제 배달 작업 반영
            int d_cnt = cap;
            while(d_cnt > 0 && last_d_idx >= 0){
                if(deliveries[last_d_idx] >= d_cnt) {
                    deliveries[last_d_idx] -= d_cnt;
                    d_cnt = 0;
                }
                else{
                    d_cnt -= deliveries[last_d_idx];
                    deliveries[last_d_idx] = 0;
                    --last_d_idx;
                }
            }
            
            // 실제 수거 작업 반영
            int p_cnt = cap;
            while(p_cnt > 0 && last_p_idx >= 0){
                if(pickups[last_p_idx] >= p_cnt) {
                    pickups[last_p_idx] -= p_cnt;
                    p_cnt = 0;
                }
                else{
                    p_cnt -= pickups[last_p_idx];
                    pickups[last_p_idx] = 0;
                    --last_p_idx;
                }
            }
        }
        
        return total_dist;
    }
}
